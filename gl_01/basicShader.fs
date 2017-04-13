#version 330 core
in vec2 TexCoord;
in vec3 Normal;  
in vec3 FragPos;  

out vec4 color;

uniform sampler2D ourTexture;
uniform vec3 lightPos;  

void main()
{
    vec3 lightColor = vec3(1.0f, 1.0f, 1.0f);

    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;

    float ambientStrength = 0.3f;
    vec3 ambient = ambientStrength * lightColor;

    vec3 result = (ambient + diffuse) * vec3(texture(ourTexture, TexCoord));
    color = vec4(result, 1.0f);

}