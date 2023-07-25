#version 410 core
out vec4 FragColor;

in vec3 FragPos;
in vec3 Normal;

uniform mat4 view;
uniform vec3 objectColor;
uniform vec3 viewPos;
uniform float viewDirX;
uniform float viewDirY;

mat3 rotationX( in float angle ) {
	return mat3(	1.0,		0,			0,	
			 		0, 	cos(angle),	-sin(angle),
					0, 	sin(angle),	 cos(angle));
}

mat3 rotationY( in float angle ) {
	return mat3(	cos(angle),		0,		sin(angle),
			 				0,		1.0,			 0,
					-sin(angle),	0,		cos(angle));
}

void main() {
    vec3 light1Direction     = vec3(-0.685f,  -0.23f,  0.691f);
    vec3 light1ColorDiffuse  = vec3(   0.8f,    0.8f,    0.8f);
    vec3 light1ColorSpecular = vec3(   0.8f,    0.8f,    0.8f);
    
    vec3 light2Direction     = vec3( 0.747f, -0.585f,  0.315f);
    vec3 light2ColorDiffuse  = vec3( 0.498f,    0.5f,    0.6f);
    vec3 light2ColorSpecular = vec3(   0.2f,    0.2f,    0.2f);
    
    vec3 light3Direction     = vec3( 0.435f,  0.789f, -0.435f);
    vec3 light3ColorDiffuse  = vec3( 0.798f,  0.838f,    1.0f);
    vec3 light3ColorSpecular = vec3( 0.066f,    0.0f,    0.0f);

    //float specularStrength = 0.9;
    vec3 norm = normalize(Normal);
    vec3 viewDir = normalize(viewPos - FragPos);

    light1Direction = rotationX(-viewDirX) * light1Direction;
    light2Direction = rotationX(-viewDirX) * light2Direction;
    light3Direction = rotationX(-viewDirX) * light3Direction;
    light1Direction = rotationY(-viewDirY) * light1Direction;
    light2Direction = rotationY(-viewDirY) * light2Direction;
    light3Direction = rotationY(-viewDirY) * light3Direction;

    vec3 diffuse1 = max(dot(norm, -light1Direction), 0.0) * light1ColorDiffuse;
    vec3 diffuse2 = max(dot(norm, -light2Direction), 0.0) * light2ColorDiffuse;
    vec3 diffuse3 = max(dot(norm, -light3Direction), 0.0) * light3ColorDiffuse;

    //vec3 specular1 = specularStrength * pow(max(dot(viewDir, reflect(light1Direction, norm)), 0.0), 2) * light1ColorSpecular;
    //vec3 specular2 = specularStrength * pow(max(dot(viewDir, reflect(light2Direction, norm)), 0.0), 2) * light2ColorSpecular;
    //vec3 specular3 = specularStrength * pow(max(dot(viewDir, reflect(light3Direction, norm)), 0.0), 2) * light3ColorSpecular;
    
    vec3 result = vec3(0, 0, 0);
    result += diffuse1;
    result += diffuse2;
    result += diffuse3;
    //result += specular1;
    //result += specular2;
    //result += specular3;
    FragColor = vec4(result * objectColor, 1.0f);
}