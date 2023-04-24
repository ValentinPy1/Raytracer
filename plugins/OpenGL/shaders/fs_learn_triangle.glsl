#version 430 core

out vec4 FragColor;

uniform vec3 focalPoint;
uniform vec2 u_resolution;

layout (std140, binding = 1) buffer ObjectsBlock {
    vec3 args[];
} objectsBlock;

struct Light {
    vec3 position;
    vec3 color;
    float radius;
};

layout (std140, binding = 2) buffer LightsBlock {
    Light lights[];
} lightsBlock;

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

vec3 getBlinnPhongColor(Light light, vec3 normal, vec3 lightDirection, vec3 intersection) {
    vec3 finalColor = vec3(0.0f, 0.0f, 0.0f);
    vec3 halfVector = normalize(lightDirection + normalize(focalPoint)); // minus, sure bout that?
    float lightDistance = distance(light.position, intersection);

    float diffuse = min(max(dot(normal, lightDirection), 0.0), 1);
    finalColor += diffuse * light.color * (1.0 - lightDistance);

    float specular =  pow(min(max(0.0f, dot(normal, halfVector)), 1.0f), 1);
    finalColor += specular * light.color * (1.0 - lightDistance);

    return finalColor;
}

void applyLight(Light light, float t, Sphere sphere) {
    vec3 intersection = rayDir * t + focalPoint;
    vec3 lightDirection = normalize(light.position - intersection);
    vec3 normal = normalize(intersection - sphere.center);

    vec3 color = getBlinnPhongColor(light, normal, lightDirection, intersection);
    // FragColor.xyz = color;
    FragColor.xyz += color;
}

void main()
{
    FragColor = vec4(0.0f, 0.0f, 0.0f, 1.0f);

//    if (distance(rayDir.xy, lightsBlock.lights[0].position.xy) < 0.6) {
//         FragColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);
//    }

    Sphere sphere = Sphere(objectsBlock.args[0], 0.5);

    float t = solveSphere(focalPoint, rayDir, sphere);
    if (t > 0.0) {
        FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
        // for (int i = 0; i < lightsBlock.lights.length(); ++i) {
        //     applyLight(lightsBlock.lights[i], t, sphere);

        // }
        applyLight(lightsBlock.lights[0], t, sphere);
    }

}
