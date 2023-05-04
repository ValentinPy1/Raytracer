import bpy
import os

def export_to_config():
    output_file = os.path.join(os.path.dirname(bpy.data.filepath), "output_config.cfg")
    scene = bpy.context.scene
    camera = scene.camera

    with open(output_file, 'w') as f:
        # Camera settings
        f.write("camera :\n{\n")
        f.write("    resolution = { width = %d; height = %d; };\n" % (scene.render.resolution_x, scene.render.resolution_y))
        f.write("    position = { x = %.2f; y = %.2f; z = %.2f; };\n" % tuple(camera.location))
        f.write("    rotation = { x = %.2f; y = %.2f; z = %.2f; };\n" % tuple(camera.rotation_euler))
        f.write("    fieldOfView = %.2f;\n" % (camera.data.angle * 180 / 3.14159265))
        f.write("};\n\n")

        # Mesh object
        f.write("primitive = {\n")
        f.write("    type = \"Mesh\";\n")
        f.write("    args = {\n")
        f.write("        primitives = (\n")

        for obj in scene.objects:
            if obj.type == 'MESH':
                for poly in obj.data.polygons:
                    f.write("            type = \"TrianglePart\";\n")
                    f.write("            args = {\n")
                    f.write("                vertices = {\n")

                    for loop_index in range(poly.loop_start, poly.loop_start + poly.loop_total):
                        f.write("                    p%d = { x = %.2f; y = %.2f; z = %.2f; };\n" % (
                            loop_index % 3 + 1,
                            *obj.data.vertices[obj.data.loops[loop_index].vertex_index].co
                        ))

                    f.write("                };\n")
                    f.write("            },\n")

        f.write("        );\n")
        f.write("    };\n")
        f.write("};\n")

# Change the output file path as needed
output_file = os.path.join(os.path.dirname(bpy.data.filepath), "output_config.txt")

export_to_config(output_file)
