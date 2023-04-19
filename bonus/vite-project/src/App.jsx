import { useState } from 'react'
import { useEffect } from 'react'
import reactLogo from './assets/react.svg'
import viteLogo from '/vite.svg'
import './App.css'
import * as THREE from 'three'
import { Canvas } from 'react-three-fiber'
function App() {
  useEffect(() => {
    const scene = new THREE.Scene()
    const camera = new THREE.PerspectiveCamera(
      75, window.innerWidth /
      window.innerHeight, 0.1, 1000)
    camera.position.z = 64
    const renderer = new THREE.WebGLRenderer({
      Canvas,
      antialias: true
    })
    renderer.setSize(window.innerWidth, window.innerHeight)
    document.body.appendChild(renderer.domElement)

    const spotLight = new THREE.SpotLight(0xffffff, 1)
    spotLight.castShadow = true
    spotLight.position.set(0, 34, 32)
    scene.add(spotLight)

    //objects
    const Box = new THREE.BoxGeometry(16, 16, 16);
    const BoxMaterial = new THREE.MeshLambertMaterial();
    const BoxMesh = new THREE.Mesh(Box, BoxMaterial);

    scene.add(BoxMesh)


    const animate = () => {
      BoxMesh.rotation.x += 0.009
      BoxMesh.rotation.y += 0.009
      renderer.render(scene, camera)
      window.requestAnimationFrame(animate)
    }
    animate()
  }, [])

    return (
    <div>
      <Canvas>
      </Canvas>
    </div>
  );
}

export default App
