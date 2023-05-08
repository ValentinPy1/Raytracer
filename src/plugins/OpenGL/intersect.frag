#version 430 core

struct Triangle {
    vec3 p1;
    vec3 p2;
    vec3 p3;
};
struct Light {
    vec3 position;
    vec3 color;
    float radius;
};

layout (std430, binding = 1) buffer ObjBlock {
    Triangle objects[];
} objBlock;

layout(std430, binding = 2) buffer LightBlock {
    Light lights[];
} lightBlock;

struct Intersection {
    float t;
    int objIndex;
    vec3 normal;
};

float solveTriangle(int objIndex, vec3 dir, vec3 orig) {
    Triangle triangle = Triangle(objBlock.objects[objIndex].p1, objBlock.objects[objIndex].p2, objBlock.objects[objIndex].p3);
    vec3 edge1 = triangle.p2 - triangle.p1;
    vec3 edge2 = triangle.p3 - triangle.p1;
    vec3 pvec = cross(dir, edge2);
    float det = dot(edge1, pvec);

    if (abs(det) < 1e-8) return -1;

    float inv_det = 1.0 / det;
    vec3 tvec = orig - triangle.p1;
    float u = dot(tvec, pvec) * inv_det;
    if (u < 0.0 || u > 1.0) return -1;

    vec3 qvec = cross(tvec, edge1);
    float v = dot(dir, qvec) * inv_det;
    if (v < 0.0 || u + v > 1.0) return -1;

    float t = dot(edge2, qvec) * inv_det;
    return t;
}

vec3 getNormal(int objIndex, vec3 point) {
    Triangle triangle = Triangle(objBlock.objects[objIndex].p1, objBlock.objects[objIndex].p2, objBlock.objects[objIndex].p3);
    return normalize(cross(triangle.p2 - triangle.p1, triangle.p3 - triangle.p1));
}

Intersection findClosestIntersection(vec3 dir, vec3 orig) {
    float t = -1;
    float tmp = -1;
    int objIndex = -1;
    for (int i = 0; i < objBlock.objects.length(); i++) {
        Triangle triangle = Triangle(
            objBlock.objects[i].position,
            objBlock.objects[i + 1].position,
            objBlock.objects[i + 2].position
        );
        if (triangle.solve(dir, orig, tmp) && (t < 0 || tmp < t)) {
            t = tmp;
            objIndex = i;
        }
    }
    if (objIndex < 0) {
        return Intersection(-1, -1, vec3(0));
    }
    return Intersection(t, objIndex, Triangle::getNormal(objBlock.objects[objIndex].position));
}

