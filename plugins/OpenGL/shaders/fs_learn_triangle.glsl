#version 430 core
out vec4 FragColor;
layout (std140, binding = 1) buffer ObjectsBlock {
    int type;
    vec3 args[];
} objectsBlock;
uniform vec3 focalPoint;
in vec3 rayDir;

struct Sphere {
    vec3 center;
    float radius;
};

// returns a negative number if there are no intersection, else returns the distance to the intersection
float solveSphere(vec3 orig, vec3 dir, Sphere sphere)
{
    float a = dot(dir, dir);
    float b = 2 * dot(dir, (orig - sphere.center));
    float c = dot((orig - sphere.center), (orig - sphere.center)) - sphere.radius * sphere.radius;
    float delta = dot(b, b) - 4 * a * c;

    if (delta < 0)
        return -1;
    float t = -b - sqrt(delta) / (2 * a);
    if (t < 0) {
        return -b + sqrt(delta) / (2 * a);
    }
    return t;
}

// float findClosestIntersectionAndSetColor(vec3 orig, vec3 dir) {
//     float min = -1;

//     // for (int i = 0; i < objectsBlock)
// }

void main()
{
    // Sphere sphere = Sphere(objectsBlock.args[0], 0.5);

    // if (solveSphere(focalPoint, rayDir, sphere) > 0.0) {
    //     FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
    // } else {
    //     FragColor = vec4(0.0f, 0.0f, 0.0f, 1.0f);
    // }
    // findClosestIntersectionAndSetColor(focalPoint, rayDir);
}
