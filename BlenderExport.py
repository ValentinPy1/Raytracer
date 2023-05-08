import bpy

def export_to_config(output_file):
    scene = bpy.context.scene
    camera_config = get_camera_config(scene)
    objects_config = get_objects_config(scene)
    lights_config = get_lights_config(scene)
    config = f'{camera_config}\n{objects_config}\n{lights_config}'

    with open(output_file, 'w') as f:
        f.write(config)

def get_camera_config(scene):
    camera = scene.camera
    cam_data = camera.data
    resolution_x = scene.render.resolution_x
    resolution_y = scene.render.resolution_y
    position = camera.location
    rotation = camera.rotation_euler
    fov = cam_data.angle

    return f'''# Configuration of the camera
extensions:
{{
    mode = ".v";
}}

camera :
{{
    captor = {{ width = {resolution_x}; height = {resolution_y}; }};
    position = {{ x = {position.x}; y = {position.y}; z = {position.z}; }};
    rotation = {{ x = {rotation.x}; y = {rotation.y}; z = {rotation.z}; }};
    focal = -1000;
}}

plugins:
{{
    wrapper = "src/plugins/libWrapper.v.so";
    plugins = (
        {{
            name = "applyIntersect";
            path = "./src/plugins/libApplyIntersect.process";
        }},
        {{
            name = "applyPointLights";
            path = "./src/plugins/libApplyPointLights.process";
        }}
    );
}}
'''

def get_objects_config(scene):
    triangles = get_triangles(scene)
    objects_entries = []

    for tri_verts in triangles:
        object_entry = f'''{{
            primitive: {{
                type = "Mesh";
                    args = {{
                        primitives = (
                            type = "TrianglePart";
                                args = {{
                                    vertices = {{
                                        p1 = {{x = {tri_verts[0].x}; y = {tri_verts[0].y}; z = {tri_verts[0].z}; }};
                                        p2 = {{x = {tri_verts[1].x}; y = {tri_verts[1].y}; z = {tri_verts[1].z}; }};
                                        p3 = {{x = {tri_verts[2].x}; y = {tri_verts[2].y}; z = {tri_verts[2].z}; }};
                                    }};
                                }};
                        );
                    }},
            }},
            material = "libFlat.material"
        }}'''
        objects_entries.append(object_entry)

    objects_entries_str = ','.join(objects_entries)

    return f'''objects:
{{
    pathObjects = "./src/plugins/";
    pathMaterial = "./src/plugins/";
    objects = (
        {objects_entries_str}
    );
}}
'''

def get_lights_config(scene):
    light_entries = []
    light_count = 1

    for light_obj in scene.objects:
        if light_obj.type == 'LIGHT':
            light = light_obj.data
            light_entry = f'''{{
            name="light{light_count}";
            type = "Directional";
            args = {{
                direction = {{ x = {light_obj.rotation_euler.x}; y = {light_obj.rotation_euler.y}; z = {light_obj.rotation_euler.z}; }},
                color = {{ r = {light.color.r * 255}; g = {light.color.g * 255}; b = {light.color.b * 255}; }},
                applyMode = "BlinnPhong";
                shadowSamples = 10;
            }};
        }}'''
            light_entries.append(light_entry)
            light_count += 1

    light_entries_str = ''.join(light_entries)

    return f'''lights:
{{
    path = "./src/plugins/";
    lights = (
        {light_entries_str}
    );
}};
'''

def get_triangles(scene):
    triangles = []

    for obj in scene.objects:
        if obj.type == 'MESH':
            mesh = obj.data
            mesh.calc_loop_triangles()

            for tri in mesh.loop_triangles:
                tri_verts = [mesh.vertices[v].co for v in tri.vertices]
                triangles.append(tri_verts)

    return triangles

output_file = "output_config.cfg"
export_to_config(output_file)
