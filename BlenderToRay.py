# EXPERIMENTAL, GOTTA TEST IT ON LINUX
# this script just takes the basic outline of the config file we had and creates it from a blender scene
# mod needed is the output file

import bpy
import os

def export_to_config(output_file):
    scene = bpy.context.scene
    camera = scene.camera

    with open(output_file, 'w') as f:
        f.write("extensions:\n{\n    mode = \".gl\";\n};\n\n")

        f.write("camera :\n{\n")
        f.write("    resolution = { width = %d; height = %d; };\n" % (scene.render.resolution_x, scene.render.resolution_y))
        f.write("    position = { x = %.2f; y = %.2f; z = %.2f; };\n" % tuple(camera.location))
        f.write("    rotation = { x = %.2f; y = %.2f; z = %.2f; };\n" % tuple(camera.rotation_euler))
        f.write("    fieldOfView = %.2f;\n" % (camera.data.angle * 180 / 3.14159265))
        f.write("};\n\n")

        # Plugins and objects
        f.write("plugins:\n{\n    wrapper = \"src/plugins/Vanille/libWrapper.v.so\";\n    plugins = ();\n}\n\n")
        f.write("objects:\n{\n    pathObjects = \"path/to/objects.so\";\n    pathTextures = \"path/to/textures.so\";\n")
        f.write("    objects = (\n")

        for obj in scene.objects:
            if obj.type == 'MESH':
                f.write("        {\n")
                f.write("            primitive = \"libTrianglePrimitive\";\n")

                for poly in obj.data.polygons:
                    for loop_index in range(poly.loop_start, poly.loop_start + poly.loop_total):
                        f.write("            vertex%d = { x = %.2f; y = %.2f; z = %.2f; };\n" % (
                            loop_index % 3 + 1,
                            *obj.data.vertices[obj.data.loops[loop_index].vertex_index].co
                        ))
                f.write("        }\n")

        f.write("    );\n};\n")


output_file = os.path.join(os.path.dirname(bpy.data.filepath), "output_config.txt")

export_to_config(output_file)
