// #version 430 core

// struct Object3D {
//     vec3 position;
//     vec3 rotation;
// };

// struct Light {
//     vec3 position;
//     vec3 color;
//     float radius;
// };

// struct Intersection {
//     float t;
//     int objIndex;
//     vec3 normal;
// };

// layout (std430, binding = 1) buffer ObjBlock {
//     Object3D objects[];
// } objBlock;

// layout(std430, binding = 2) buffer LightBlock {
//     Light lights[];
// } lightBlock;

// vec4 traceRay(vec3 focalPoint, vec3 rayDir, int reflectDepth);
// Intersection findClosestIntersection(vec3 dir, vec3 orig);

// vec4 getReflectionColor(vec3 dir, vec3 orig, vec3 normal, int objIndex, int depth) {
//     if (depth <= 0) {
//         return vec4(0.0, 0.0, 0.0, 1.0);
//     }
//     vec3 reflectionDir = reflect(dir, normal);
//     vec3 reflectionOrig = orig + reflectionDir * 0.001;
//     // vec4 reflectionColor = traceRay(reflectionOrig, reflectionDir, depth - 1);
//     // vec4 reflectionColor = traceRay(reflectionOrig, reflectionDir, depth);
//     return reflectionColor;

// }
