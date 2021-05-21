#version 400 core

in vec2 TexCoord;

out vec4 color;

uniform sampler2D ourTexture;
uniform float red;

void main()
{
    color = texture(ourTexture, TexCoord) * vec4(vec3(red, 1.0, 1.0), 1.0);
}
