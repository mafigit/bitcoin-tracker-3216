#include "led_matrix.h"

#define DATA_PIN 6
#define CLK_PIN 9
#define WRCLK_PIN 7
#define CS_PIN 8

static LEDMatrix* matrix;


void setup()
{
  Serial.begin(9600);
  matrix = new LEDMatrix(DATA_PIN, CLK_PIN, WRCLK_PIN, CS_PIN);
}

int xpos = 0;
int ypos = 0;

int zero[8] = {
  B00000000,
  B01110000,
  B11011000,
  B11011000,
  B11011000,
  B11011000,
  B11011000,
  B01110000
};
int one[8] = {
  B00000000,
  B01100000,
  B11100000,
  B01100000,
  B01100000,
  B01100000,
  B01100000,
  B11110000
};
int two[8] = {
  B00000000,
  B01110000,
  B10001000,
  B00001000,
  B00010000,
  B00100000,
  B01000000,
  B11111000
};
int three[8] = {
  B00000000,
  B11111000,
  B00010000,
  B00100000,
  B00010000,
  B00001000,
  B10001000,
  B01110000
};
int four[8] = {
  B00000000,
  B00010000,
  B00110000,
  B01010000,
  B10010000,
  B11111000,
  B00010000,
  B00010000
};
int five[8] = {
  B00000000,
  B11111000,
  B10000000,
  B11110000,
  B00001000,
  B00001000,
  B10001000,
  B01110000
};
int six[8] = {
  B00000000,
  B00110000,
  B01000000,
  B10000000,
  B11110000,
  B10001000,
  B10001000,
  B01110000
};
int seven[8] = {
  B00000000,
  B11111000,
  B00001000,
  B00010000,
  B00100000,
  B01000000,
  B10000000,
  B10000000
};
int eight[8] = {
  B00000000,
  B01110000,
  B10001000,
  B10001000,
  B01110000,
  B10001000,
  B10001000,
  B01110000
};
int nine[8] = {
  B00000000,
  B01110000,
  B10001000,
  B10001000,
  B01111000,
  B00001000,
  B00010000,
  B01100000
};

int a[8] = {
  B00000000,
  B00000000,
  B00000000,
  B01110000,
  B00001000,
  B01111000,
  B10001000,
  B01111000
};
int b[8] = {
  B10000000,
  B10000000,
  B10000000,
  B11110000,
  B10001000,
  B10001000,
  B10001000,
  B11110000
};
int c[8] = {
  B00000000,
  B00000000,
  B00000000,
  B01110000,
  B10001000,
  B10000000,
  B10000000,
  B01111000
};
int d[8] = {
  B00001000,
  B00001000,
  B00001000,
  B01111000,
  B10001000,
  B10001000,
  B10001000,
  B01111000
};
int e[8] = {
  B00000000,
  B00000000,
  B00000000,
  B01110000,
  B10001000,
  B11111000,
  B10000000,
  B01111000
};
int f[8] = {
  B00110000,
  B01000000,
  B11100000,
  B01000000,
  B01000000,
  B01000000,
  B01000000,
  B01000000
};
int g[8] = {
  B00000000,
  B01110000,
  B10010000,
  B10010000,
  B10010000,
  B01110000,
  B00010000,
  B11100000
};
int h[8] = {
  B00000000,
  B10000000,
  B10000000,
  B11100000,
  B10010000,
  B10010000,
  B10010000,
  B10010000
};
int i[8] = {
  B00000000,
  B10000000,
  B00000000,
  B10000000,
  B10000000,
  B10000000,
  B10000000,
  B10000000
};
int j[8] = {
  B00000000,
  B00100000,
  B00000000,
  B00100000,
  B00100000,
  B00100000,
  B00100000,
  B11000000
};
int k[8] = {
  B00000000,
  B10000000,
  B10000000,
  B10010000,
  B10100000,
  B11000000,
  B10100000,
  B10010000
};
int l[8] = {
  B00000000,
  B11000000,
  B01000000,
  B01000000,
  B01000000,
  B01000000,
  B01000000,
  B11100000
};
int m[8] = {
  B00000000,
  B00000000,
  B00000000,
  B01110000,
  B10101000,
  B10101000,
  B10101000,
  B10101000
};
int n[8] = {
  B00000000,
  B00000000,
  B00000000,
  B11110000,
  B10001000,
  B10001000,
  B10001000,
  B10001000
};
int o[8] = {
  B00000000,
  B00000000,
  B00000000,
  B01110000,
  B10001000,
  B10001000,
  B10001000,
  B01110000
};
int p[8] = {
  B00000000,
  B00000000,
  B00000000,
  B11110000,
  B10001000,
  B11110000,
  B10000000,
  B10000000
};
int q[8] = {
  B00000000,
  B00000000,
  B00000000,
  B01111000,
  B10001000,
  B01111000,
  B00001000,
  B00001000
};
int r[8] = {
  B00000000,
  B00000000,
  B00000000,
  B10110000,
  B11001000,
  B10000000,
  B10000000,
  B10000000
};
int s[8] = {
  B00000000,
  B00000000,
  B00000000,
  B01111000,
  B10000000,
  B01110000,
  B00001000,
  B11110000
};
int t[8] = {
  B00000000,
  B01000000,
  B01000000,
  B11100000,
  B01000000,
  B01000000,
  B01001000,
  B00110000
};
int u[8] = {
  B00000000,
  B00000000,
  B00000000,
  B10001000,
  B10001000,
  B10001000,
  B10011000,
  B01101000
};
int v[8] = {
  B00000000,
  B00000000,
  B00000000,
  B10001000,
  B10001000,
  B10001000,
  B01010000,
  B00100000
};
int w[8] = {
  B00000000,
  B00000000,
  B00000000,
  B10001000,
  B10001000,
  B10101000,
  B10101000,
  B11111000
};
int x[8] = {
  B00000000,
  B00000000,
  B00000000,
  B10001000,
  B01010000,
  B00100000,
  B01010000,
  B10001000
};
int y[8] = {
  B00000000,
  B00000000,
  B00000000,
  B10001000,
  B10001000,
  B01111000,
  B00001000,
  B11110000
};
int z[8] = {
  B00000000,
  B00000000,
  B00000000,
  B11111000,
  B00010000,
  B00100000,
  B01000000,
  B11111000
};
int bitcoin1[8] = {
  B00000000,
  B00011000,
  B11111100,
  B01011010,
  B01011011,
  B01011011,
  B01011010,
  B01111100
};
int bitcoin2[8] = {
  B01111100,
  B01011010,
  B01011011,
  B01011011,
  B01011010,
  B11111100,
  B00011000,
  B00000000
};


int color = 0;
void drawletter(char letter, int X, int Y) {
  xpos = X;
  ypos = Y;
  switch(letter) {
    case '0': draw_final(zero);break;
    case '1': draw_final(one);break;
    case '2': draw_final(two);break;
    case '3': draw_final(three);break;
    case '4': draw_final(four);break;
    case '5': draw_final(five);break;
    case '6': draw_final(six);break;
    case '7': draw_final(seven);break;
    case '8': draw_final(eight);break;
    case '9': draw_final(nine);break;
    case 'a': draw_final(a);break;
    case 'b': draw_final(b);break;
    case 'c': draw_final(c);break;
    case 'd': draw_final(d);break;
    case 'e': draw_final(e);break;
    case 'f': draw_final(f);break;
    case 'g': draw_final(g);break;
    case 'h': draw_final(h);break;
    case 'i': draw_final(i);break;
    case 'j': draw_final(j);break;
    case 'k': draw_final(k);break;
    case 'l': draw_final(l);break;
    case 'm': draw_final(m);break;
    case 'n': draw_final(n);break;
    case 'o': draw_final(o);break;
    case 'p': draw_final(p);break;
    case 'q': draw_final(q);break;
    case 'r': draw_final(r);break;
    case 's': draw_final(s);break;
    case 't': draw_final(t);break;
    case 'u': draw_final(u);break;
    case 'v': draw_final(v);break;
    case 'w': draw_final(w);break;
    case 'x': draw_final(x);break;
    case 'y': draw_final(y);break;
    case 'z': draw_final(z);break;
    case 'A': draw_final(bitcoin1);break;
    case 'B': draw_final(bitcoin2);break;
    default: break;
  }
}

void draw_final(int array[8]) {
  int final_array[8][8];
  for (int i=0; i<=7; i++) {
    int mask = B10000000;
    for (int j=0; j<=7; j++) {
      int tmp =  array[i]&mask;
        if (tmp == mask) {
          final_array[i][j] = 1;
        }
        else {
          final_array[i][j] = 0;
        }
      mask >>= 1;
    }
  }
  for (int k=0; k<=7; k++) {
    for (int l=0; l<=7; l++) {
      if(final_array[l][k] == 1) {
        if(color == 0)
          matrix->plot(k+xpos,l+ypos,RED);
        else
          matrix->plot(k+xpos,l+ypos,GREEN);
      }
    }
  }
}

int cursor_posx = 0;
int cursor_posy = 0;


void loop()
{
  if (Serial.available()) {
    char letter = Serial.read();
    if(letter == ' ') {
      cursor_posx = cursor_posx + 3;
    }
    if(letter == 'C' ) {
      cursor_posx = 0;
      cursor_posy = 0;
      matrix->clear();
      matrix->render();
      matrix->clear();
    }
    if(letter == '$' ) {
      drawletter('A', 0, 0);
      drawletter('B', 0, 8);
      cursor_posx = 0;
      cursor_posy = 0;
    }
    if(letter == '!' ) {
      cursor_posx = 2;
      cursor_posy = 8;
    }
    if(letter == '&' ) {
      color = 1;
      cursor_posx = cursor_posx - 6;
    }
    if(letter == '%' ) {
      color = 0;

    }
    else {
      drawletter(letter, cursor_posx, cursor_posy);
      if (letter=='$') {
        cursor_posx = cursor_posx + 2;
      }
      if (letter=='i') {
        cursor_posx = cursor_posx + 2;
      }
      else {
        cursor_posx = cursor_posx + 6;
      }
    }
  }
  matrix->render();
}
