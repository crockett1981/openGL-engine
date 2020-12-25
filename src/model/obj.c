//
// Created by holmes on 12/12/2020.
//

#include "model.h"

int load_obj_file(mesh_t *mesh, const char *file_name) {

    int point_count = 0;

    int index1 = 0;
    int index2 = 0;
    int index3 = 0;

    vec3* v = NULL;
    vec2* vt = NULL;
    vec3* vn = NULL;

    v = (vec3*)malloc(index1 * sizeof(vec3*));
    vt = (vec2*)malloc(index2 * sizeof(vec2*));
    vn = (vec3*)malloc(index3 * sizeof(vec3*));

    mesh->vertices = (vec3*)malloc(0 * sizeof(vec3*));
    mesh->texture_coordinates = (vec2*)malloc(0 * sizeof(vec2*));
    mesh->normals = (vec3*)malloc(0 * sizeof(vec3*));

    FILE *file = fopen(file_name, "r");
    if(file == NULL) {
        printf("File not found\n");
        return -1;
    }

    while(1) {
        char lineheader[128] = {'\0'};

        int res = fscanf(file, "%s", lineheader);
        if(res == EOF)
            break;

        if(strcmp(lineheader, "v") == 0) {
            v = realloc(v, (index1 + 1) * sizeof(vec3));

            if(fscanf(file, "%f %f %f\n", &v[index1][0], &v[index1][1], &v[index1][2]));

            ++index1;
        }
        else if(strcmp(lineheader, "vt") == 0) {
            vt = realloc(vt, (index2 + 1) * sizeof(vec2));

            if(fscanf(file, "%f %f\n", &vt[index2][0], &vt[index2][1]));

            ++index2;
        }
        else if(strcmp(lineheader, "vn") == 0) {
            vn = realloc(vn, (index3 + 1) * sizeof(vec3));

            if (fscanf(file, "%f %f %f\n", &vn[index3][0], &vn[index3][1], &vn[index3][2]));

            ++index3;
        }
        else if(strcmp(lineheader, "f") == 0) {
            int vf[3], vtf[3], vnf[3];

            if(fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vf[0], &vtf[0], &vnf[0], &vf[1], &vtf[1], &vnf[1], &vf[2], &vtf[2], &vnf[2]));

            /* Validation */
            for(short i = 0; i < 3; ++i) {

                if((vf[i] - 1 < 0) || (vf[i] - 1 >= index1)) {
                    printf("Error\n");
                    return -1;
                }

                if((vtf[i] - 1 < 0) || (vtf[i] - 1 >= index2)) {
                    printf("Error\n");
                    return -1;
                }

                if((vnf[i] - 1 < 0) || (vnf[i] - 1 >= index3)) {
                    printf("Error\n");
                    return -1;
                }

                mesh->vertices = realloc(mesh->vertices, (point_count + 1) * sizeof(vec3));
                mesh->vertices[point_count][0] = v[vf[i] - 1][0];
                mesh->vertices[point_count][1] = v[vf[i] - 1][1];
                mesh->vertices[point_count][2] = v[vf[i] - 1][2];

                mesh->texture_coordinates = realloc(mesh->texture_coordinates, (point_count + 1) * sizeof(vec2));
                mesh->texture_coordinates[point_count][0] = vt[vtf[i] - 1][0];
                mesh->texture_coordinates[point_count][1] = vt[vtf[i] - 1][1];

                mesh->normals = realloc(mesh->normals, (point_count + 1) * sizeof(vec3));
                mesh->normals[point_count][0] = vn[vnf[i] - 1][0];
                mesh->normals[point_count][1] = vn[vnf[i] - 1][1];
                mesh->normals[point_count][2] = vn[vnf[i] - 1][2];

                ++point_count;
            }
        }
    }

    mesh->count = point_count;

    free(v);
    v = NULL;

    free(vn);
    vn = NULL;

    free(vt);
    vt = NULL;

    return 0;
}
