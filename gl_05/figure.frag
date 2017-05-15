#version 330 core

#define ambientStrength 0.1f
#define specularStrength 0.5f

in vec3 fragPos;
in vec3 vecNormal;
in vec2 TexCoord;

out vec4 color;

uniform sampler2D Texture0;
uniform vec3 lightPos;
uniform vec3 lightColor;
uniform vec3 viewPos;

void main()
{
    // Ambient
    vec3 ambient = ambientStrength * lightColor;
  	
    // Diffuse 
    vec3 norm = normalize(vecNormal);
    vec3 lightDir = normalize(lightPos - fragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;
    
    // Specular
    vec3 viewDir = normalize(viewPos - fragPos);
    vec3 reflectDir = reflect(-lightDir, norm);  
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = specularStrength * spec * lightColor;  
        
	color = texture(Texture0, TexCoord) * vec4(ambient + diffuse + specular, 1.0f);
}
