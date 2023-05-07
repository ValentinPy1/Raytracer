import * as THREE from 'three';
import axios from 'axios';
import {
    EventDispatcher,
    MOUSE,
    Quaternion,
    Spherical,
    TOUCH,
    Vector2,
    Vector3
    // OrbitControls
} from 'three';

// var renderer = new THREE.WebGLRenderer();
// renderer.setPixelRatio(window.devicePixelRatio);
// renderer.setSize(window.innerWidth, window.innerHeight);
// document.getElementById('app').appendChild(renderer.domElement);

// var scene = new THREE.Scene();

// var camera = new THREE.PerspectiveCamera(75, window.innerWidth / window.innerHeight, 1, 10000);

// camera.position.z = 500;
// camera.position.y = 500;

// camera.lookAt(scene.position);

// var geometry = new THREE.SphereGeometry(200, 20, 20);

// var material = new THREE.MeshBasicMaterial({
//     color: 0x00ff00,
//     wireframe: true
// });

// var sphere = new THREE.Mesh(geometry, material);

// sphere.position.set(10, 0, 0);

// scene.add(sphere);

// function animate() {
//     requestAnimationFrame(animate);
//     sphere.rotation.x += 0.01;
//     sphere.rotation.y += 0.01;
//     renderer.render(scene, camera);
// }

// // get the click event from index.html

// document.getElementById('app').addEventListener('click', function () {
//     console.log('click');
// });

// animate();

///////////////////////////////////////////////


var camera = new THREE.PerspectiveCamera(30, window.innerWidth / window.innerHeight, 1, 1500);
camera.position.set(-35, 70, 100);
camera.lookAt(new THREE.Vector3(0, 0, 0));

var renderer = new THREE.WebGLRenderer({ antialias: true });
renderer.setPixelRatio(window.devicePixelRatio);
renderer.setSize(window.innerWidth, window.innerHeight);
renderer.shadowMap.enabled = true;
document.body.appendChild(renderer.domElement);

export function onWindowResize() {
    camera.aspect = window.innerWidth / window.innerHeight;
    camera.updateProjectionMatrix();
    renderer.setSize(window.innerWidth, window.innerHeight);
}
window.addEventListener('resize', onWindowResize);

var scene = new THREE.Scene()
scene.background = new THREE.Color(0xbfd1e5);

export function animate() {
    dragObject();
    renderer.render(scene, camera);
    requestAnimationFrame(animate);
    return
}

// ambient light
let hemiLight = new THREE.AmbientLight(0xffffff, 0.20);
scene.add(hemiLight);

//Add directional light
let dirLight = new THREE.DirectionalLight(0xffffff, 1);
dirLight.position.set(-30, 50, -30);
scene.add(dirLight);
dirLight.castShadow = true;
dirLight.shadow.mapSize.width = 2048;
dirLight.shadow.mapSize.height = 2048;
dirLight.shadow.camera.left = -70;
dirLight.shadow.camera.right = 70;
dirLight.shadow.camera.top = 70;
dirLight.shadow.camera.bottom = -70;

function createFloor() {
    let pos = { x: 0, y: -1, z: 3 };
    let scale = { x: 100, y: 2, z: 100 };

    let blockPlane = new THREE.Mesh(new THREE.BoxBufferGeometry(),
        new THREE.MeshPhongMaterial({ color: 0xffffff }));
    blockPlane.position.set(pos.x, pos.y, pos.z);
    blockPlane.scale.set(scale.x, scale.y, scale.z);
    blockPlane.castShadow = true;
    blockPlane.receiveShadow = true;
    scene.add(blockPlane);

    blockPlane.userData.ground = true
}

// box
function createBox() {
    let scale = { x: 6, y: 6, z: 6 }
    let pos = { x: 15, y: scale.y / 2, z: 15 }

    let box = new THREE.Mesh(new THREE.BoxBufferGeometry(),
        new THREE.MeshPhongMaterial({ color: 0xDC143C }));
    box.position.set(pos.x, pos.y, pos.z);
    box.scale.set(scale.x, scale.y, scale.z);
    box.castShadow = true;
    box.receiveShadow = true;
    scene.add(box)

    box.userData.draggable = true
    box.userData.name = 'BOX'
}

function createTriangle() {
    let scale = { x: 6, y: 6, z: 6 }
    let pos = { x: -15, y: scale.y / 2, z: -15 }

    // let triangle = new THREE.Mesh(new THREE.TriangleBufferGeometry(),
        // new THREE.MeshPhongMaterial({ color: 0x00FF00 }));
    let triangle = new THREE.Mesh(new THREE.ConeBufferGeometry(),
        new THREE.MeshPhongMaterial({ color: 0x00FF00 }));
    triangle.position.set(pos.x, pos.y, pos.z);
    triangle.scale.set(scale.x, scale.y, scale.z);
    triangle.castShadow = true;
    triangle.receiveShadow = true;
    scene.add(triangle)

    triangle.userData.draggable = true
    triangle.userData.name = 'TRIANGLE'
}


function createSphere() {
    let radius = 4;
    let pos = { x: 15, y: radius, z: -15 };

    let sphere = new THREE.Mesh(new THREE.SphereBufferGeometry(radius, 32, 32),
        new THREE.MeshPhongMaterial({ color: 0x43a1f4 }))
    sphere.position.set(pos.x, pos.y, pos.z)
    sphere.castShadow = true
    sphere.receiveShadow = true
    scene.add(sphere)

    sphere.userData.draggable = true
    sphere.userData.name = 'Cercle'
}

function createCylinder() {
    let radius = 4;
    let height = 6
    let pos = { x: -15, y: height / 2, z: 15 };

    let cylinder = new THREE.Mesh(new THREE.CylinderBufferGeometry(radius, radius, height, 32),
        new THREE.MeshPhongMaterial({ color: 0x90ee90 }))
    cylinder.position.set(pos.x, pos.y, pos.z)
    cylinder.castShadow = true
    cylinder.receiveShadow = true
    scene.add(cylinder)

    cylinder.userData.draggable = true
    cylinder.userData.name = 'CYLINDER'
}

const raycaster = new THREE.Raycaster();
const clickMouse = new THREE.Vector2();
const moveMouse = new THREE.Vector2();
var draggable

function intersect(pos) {
    raycaster.setFromCamera(pos, camera);
    return raycaster.intersectObjects(scene.children);
}
///////////////////////////////// MENU
function openMenu(event, draggable) {
    event.preventDefault(); // Prevent the default context menu from appearing

    // Create your own custom menu here
    const menu = document.createElement('div');
    //   height: 200px;
    // width: 50%;
    menu.style.height = '50%';
    menu.style.width = '20%';
    menu.style.position = 'absolute';
    // menu.style.top = `${event.clientY}px`;
    // menu.style.left = `${event.clientX}px`;
    menu.style.top = '0%';
    menu.style.left = '80%';
    menu.style.backgroundColor = 'white';
    menu.style.padding = '10px';
    // create a button to delete the object
    const deleteButton = document.createElement('Button');
    deleteButton.style.width = '100%';
    // color
    // deleteButton.style.backgroundColor = 'red';
    deleteButton.style.color = 'black';
    deleteButton.textContent = 'delete';

    //

    deleteButton.addEventListener('click', () => {
        scene.remove(draggable);
    });

    // Add menu items to modify object parameters
    if (draggable.userData.name === 'BOX') {
        const sizeLabel = document.createElement('label');
        sizeLabel.textContent = 'Size:';
        const sizeInput = document.createElement('input');
        sizeInput.type = 'number';
        sizeInput.value = draggable.userData.scale.x.toString();
        sizeInput.addEventListener('input', (event) => {
            // const size = parseFloat((event.target as HTMLInputElement).value);
            draggable.userData.scale.set(size, size, size);
        });
        menu.appendChild(sizeLabel);
        menu.appendChild(sizeInput);

    } else if (draggable.userData.name === 'Cercle') {
        // Add menu items for sphere parameters
        // ...
    } else if (draggable.userData.name === 'CYLINDER') {
        // Add menu items for cylinder parameters
        // ...
    }

    // Add menu to DOM
    document.body.appendChild(menu);
    menu.appendChild(deleteButton);

    // Add event listener to remove menu when clicking outside of it
    const removeMenu = () => {
        document.body.removeChild(menu);
        window.removeEventListener('click', removeMenu);
    };
    window.addEventListener('click', removeMenu);
}

///////////////////MOUSE EVENT:

window.addEventListener('contextmenu', (event) => { //right click

    clickMouse.x = (event.clientX / window.innerWidth) * 2 - 1;
    clickMouse.y = -(event.clientY / window.innerHeight) * 2 + 1;

    const found = intersect(clickMouse);
    if (found.length > 0) {
        if (found[0].object.userData.ground) {
            console.log('ground')
        }
    }
    found[0].object.position.set(0, 3, 0)
    openMenu(event, found[0].object)
    console.log(found)
});

window.addEventListener('click', event => { // left click
    //check if it is clik left or right
    console.log(event.button)
    if (event.button == 2) {
        console.log('right click')
    } else {
        console.log('left click')
    }

    if (draggable != null) {
        console.log(`dropping draggable ${draggable.userData.name}`)
        draggable = null
        return;
    }

    clickMouse.x = (event.clientX / window.innerWidth) * 2 - 1;
    clickMouse.y = -(event.clientY / window.innerHeight) * 2 + 1;

    const found = intersect(clickMouse);
    if (found.length > 0) {
        if (found[0].object.userData.draggable) {
            draggable = found[0].object
            console.log(`found draggable ${draggable.userData.name}`)
        }
    }
})

window.addEventListener('mousemove', event => {
    moveMouse.x = (event.clientX / window.innerWidth) * 2 - 1;
    moveMouse.y = -(event.clientY / window.innerHeight) * 2 + 1;
});

/////////////////////////////////////////////////////

function dragObject() {
    if (draggable != null) {
        const found = intersect(moveMouse);
        if (found.length > 0) {
            for (let i = 0; i < found.length; i++) {
                if (!found[i].object.userData.ground)
                    continue

                let target = found[i].point;
                draggable.position.x = target.x
                draggable.position.z = target.z
            }
        }
    }
}

function SaveData() {
    console.log(JSON.stringify(scene.children))
    var children = JSON.stringify(scene.children)
    axios.post("http://localhost:8000/save/", {
        data: children
    }).then((res) => {
        console.log(res)
    }
    ).catch((err) => {
        console.log(err)
    })
}

function createMenu() {
    const titleMenu = document.createElement('div');
    titleMenu.classList.add('title-menu'); // Add a CSS class for styling

    // Create a heading element
    const titleHeading = document.createElement('Menu');
    titleHeading.id = 'saveButton';
    titleHeading.style.color = 'black';
    titleHeading.style.fontSize = '50px';
    titleHeading.style.fontFamily = 'Arial';
    titleHeading.style.position = 'absolute';
    // titleHeading.style.top = '0%';
    // titleHeading.style.left = '0%';
    titleHeading.textContent = 'Menu Save'; // Set the text content of the heading
    titleMenu.appendChild(titleHeading); // Append the heading to the title menu

    // handle click on it
    titleMenu.addEventListener('click', () => {
        console.log('click on menu')
        SaveData();
    });

    // Append the title menu to the body of the document
    document.body.appendChild(titleMenu);
}

createMenu()
createFloor()
// createBox()
createSphere()
// createCylinder()
// createTriangle()

animate()
