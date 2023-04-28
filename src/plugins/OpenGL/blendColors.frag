#version 430 core

vec4 blendMultiply(vec4 c1, vec4 c2) {
  return vec4(c1.rgb * c2.rgb, c1.a * c2.a);
}

vec4 blendAdd(vec4 c1, vec4 c2) {
    return vec4(c1.rgb + c2.rgb, c1.a + c2.a);
}
