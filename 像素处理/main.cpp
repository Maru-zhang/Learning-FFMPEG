#include<iostream>

int simplest_yuv420_split(char * url, int w, int h, int frame) {
  FILE *fp = fopen(url, "rb+");
  FILE *fp1 = fopen("output/420_y.y", "wb+");
  FILE *fp2 = fopen("output/420_u.y", "wb+");
  FILE *fp3 = fopen("output/420_v.y", "wb+");
  
  unsigned char * pic = (unsigned char *)malloc(w*h*3/2);

  for (int i = 0; i < frame; i++) {
    fread(pic, 1, w*h*3/2, fp);
    fwrite(pic, 1, w*h, fp1);
    fwrite(pic+w*h, 1,w*h / 4, fp2);
    fwrite(pic+w*h*5/4, 1, w*h/4, fp3);
  }

  free(pic);
  fclose(fp);
  fclose(fp1);
  fclose(fp2);
  fclose(fp3);

  return 0;
}

int main() {
  simplest_yuv420_split("./lena_256x256_yuv420p.yuv", 256, 256, 1);
  return 0;
}
