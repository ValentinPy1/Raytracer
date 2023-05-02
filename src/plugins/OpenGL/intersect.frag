#version 430 core

struct Sphere {
    vec3 center;
    float radius;
};

struct Object3D {
    vec3 position;
    vec3 rotation;
};

struct Light {
    vec3 position;
    vec3 color;
    float radius;
};

layout (std430, binding = 1) buffer ObjBlock {
    Object3D objects[];
} objBlock;

layout(std430, binding = 2) buffer LightBlock {
    Light lights[];
} lightBlock;

struct Intersection {
    float t;
    int objIndex;
    vec3 normal;
};

float solveSphere(int objIndex, vec3 dir, vec3 orig) {
    Sphere sphere = Sphere(objBlock.objects[objIndex].position, 0.3f); // TODO get the radius from the objects
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

vec3 getNormal(int objIndex, vec3 point) {
    return normalize(point - objBlock.objects[objIndex].position);
}

Intersection findClosestIntersection(vec3 dir, vec3 orig) {
    float t = -1;
    float tmp = -1;
    int objIndex = 0;
    // solving for sphere, but this will change in the future
    for (int i = 0; i < objBlock.objects.length() + 1; i++) {
        tmp = solveSphere(i, dir, orig);
        if (tmp > 0 && (t < 0 || tmp < t)) {
            t = tmp;
            objIndex = i;
        }
    }
    return Intersection(t, objIndex, getNormal(objIndex, orig + dir * t));
}
