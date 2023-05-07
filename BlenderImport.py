import bpy
import os


config_file = 'path/to/config.cfg'

def create_camera(config):
    cam_data = bpy.data.cameras.new("Camera")
    cam = bpy.data.objects.new("Camera", cam_data)
    cam.location = (config['position']['x'], config['position']['y'], config['position']['z'])
    cam.rotation_euler = (config['rotation']['x'], config['rotation']['y'], config['rotation']['z'])
    bpy.context.collection.objects.link(cam)
    bpy.context.scene.camera = cam

def create_lights(config):
    for light_config in config['lights']:
        light_data = bpy.data.lights.new(name=light_config['name'], type=light_config['type'].upper())
        light = bpy.data.objects.new(name=light_config['name'], object_data=light_data)
        light.location = (light_config['args']['direction']['x'], light_config['args']['direction']['y'], light_config['args']['direction']['z'])
        light.data.energy = light_config['args']['color']['r']
        bpy.context.collection.objects.link(light)

def create_objects(config):
    for obj_config in config['objects']:
        mesh = bpy.data.meshes.new("Mesh")
        obj = bpy.data.objects.new("Mesh", mesh)
        obj.location = (0, 0, 0)
        bpy.context.collection.objects.link(obj)

        vertices = []
        faces = []

        for idx, primitive in enumerate(obj_config['primitive']['args']['primitives']):
            for key, value in primitive['args']['vertices'].items():
                vertices.append((value['x'], value['y'], value['z']))
            faces.append((3 * idx, 3 * idx + 1, 3 * idx + 2))

        mesh.from_pydata(vertices, [], faces)

def parse_config(config_file):
    config_data = {}

    with open(config_file, 'r') as file:
        lines = file.readlines()
        for line in lines:
            line = line.strip()
            if line.startswith("position") or line.startswith("rotation") or line.startswith("direction") or line.startswith("color"):
                key = line.split('=')[0].strip()
                values = line.split('=')[1].strip().strip('{').strip('}').split(';')
                config_data[key] = {
                    'x': float(values[0].split('=')[1].strip()),
                    'y': float(values[1].split('=')[1].strip()),
                    'z': float(values[2].split('=')[1].strip())
                }
            elif line.startswith("captor") or line.startswith("args"):
                key = line.split('=')[0].strip()
                values = line.split('=')[1].strip().strip('{').strip('}').split(';')
                config_data[key] = {
                    'width': int(values[0].split('=')[1].strip()),
                    'height': int(values[1].split('=')[1].strip())
                }

    return config_data

config_data = parse_config(config_file)

bpy.ops.wm.read_factory_settings(use_empty=True)

create_camera(config_data)
create_lights(config_data)
create_objects(config_data)
