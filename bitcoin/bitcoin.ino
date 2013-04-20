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


int zero[7] = {
  B0011100,
  B0110110,
  B0110110,
  B0110110,
  B0110110,
  B0110110,
  B0011100
};
int one[7] = {
  B0001000,
  B0011000,
  B0001000,
  B0001000,
  B0001000,
  B0001000,
  B0001000
};
int two[7] = {
  B0011100,
  B0100010,
  B0000010,
  B0000100,
  B0001000,
  B0010000,
  B0111110
};
int three[7] = {
  B0111110,
  B0000100,
  B0001000,
  B0000100,
  B0000010,
  B0100010,
  B0011100
};
int four[7] = {
  B0000100,
  B0001100,
  B0010100,
  B0100100,
  B0111110,
  B0000100,
  B0000100
};
int five[7] = {
  B0111110,
  B0100000,
  B0111100,
  B0000010,
  B0000010,
  B0100010,
  B0011100
};
int six[7] = {
  B0001100,
  B0010000,
  B0100000,
  B0111100,
  B0100010,
  B0100010,
  B0011100
};
int seven[7] = {
  B0111110,
  B0000010,
  B0000100,
  B0001000,
  B0010000,
  B0100000,
  B0100000
};
int eight[7] = {
  B0011100,
  B0100010,
  B0100010,
  B0011100,
  B0100010,
  B0100010,
  B0011100
};
int nine[7] = {
  B0011100,
  B0100010,
  B0100010,
  B0011110,
  B0000010,
  B0000100,
  B0011000
};

int a[7] = {
  B0000000,
  B0000000,
  B0011100,
  B0000010,
  B0011110,
  B0100010,
  B0011110
};
int b[7] = {
  B0100000,
  B0100000,
  B0100000,
  B0111100,
  B0100010,
  B0100010,
  B0111100
};
int c[7] = {
  B0000000,
  B0000000,
  B0011100,
  B0100010,
  B0100000,
  B0100000,
  B0011110
};
int d[7] = {
  B0000010,
  B0000010,
  B0000010,
  B0011110,
  B0100010,
  B0100010,
  B0011110
};
int e[7] = {
  B0000000,
  B0000000,
  B0011100,
  B0100010,
  B0111110,
  B0100000,
  B0011110
};
int f[7] = {
  B0001100,
  B0010000,
  B0111000,
  B0010000,
  B0010000,
  B0010000,
  B0010000
};
int g[7] = {
  B0000000,
  B0111100,
  B0100100,
  B0100100,
  B0011100,
  B0000100,
  B0111000
};
int h[7] = {
  B0100000,
  B0100000,
  B0100000,
  B0111100,
  B0100100,
  B0100100,
  B0100100
};
int i[7] = {
  B0001000,
  B0000000,
  B0001000,
  B0001000,
  B0001000,
  B0001000,
  B0001000
};
int j[7] = {
  B0001000,
  B0000000,
  B0001000,
  B0001000,
  B0001000,
  B0001000,
  B0110000
};
int k[7] = {
  B0100000,
  B0100000,
  B0100100,
  B0101000,
  B0110000,
  B0101000,
  B0100100
};
int l[7] = {
  B0011000,
  B0001000,
  B0001000,
  B0001000,
  B0001000,
  B0001000,
  B0011100
};
int m[7] = {
  B0000000,
  B0000000,
  B0011100,
  B0101010,
  B0101010,
  B0101010,
  B0101010
};
int n[7] = {
  B0000000,
  B0000000,
  B0111100,
  B0100010,
  B0100010,
  B0100010,
  B0100010
};
int o[7] = {
  B0000000,
  B0000000,
  B0011100,
  B0100010,
  B0100010,
  B0100010,
  B0011100
};
int p[7] = {
  B0000000,
  B0000000,
  B0111100,
  B0100010,
  B0111100,
  B0100000,
  B0100000
};
int q[7] = {
  B0000000,
  B0000000,
  B0011110,
  B0100010,
  B0011110,
  B0000010,
  B0000010
};
int r[7] = {
  B0000000,
  B0000000,
  B0101100,
  B0110010,
  B0100000,
  B0100000,
  B0100000
};
int s[7] = {
  B0000000,
  B0000000,
  B0011110,
  B0100000,
  B0011100,
  B0000010,
  B0111100
};
int t[7] = {
  B0010000,
  B0010000,
  B0111000,
  B0010000,
  B0010000,
  B0010010,
  B0001100
};
int u[7] = {
  B0000000,
  B0000000,
  B0100010,
  B0100010,
  B0100010,
  B0100110,
  B0011010
};
int v[7] = {
  B0000000,
  B0000000,
  B0100010,
  B0100010,
  B0100010,
  B0010100,
  B0001000
};
int w[7] = {
  B0000000,
  B0000000,
  B0100010,
  B0100010,
  B0101010,
  B0101010,
  B0111110
};
int x[7] = {
  B0000000,
  B0000000,
  B0100010,
  B0010100,
  B0001000,
  B0010100,
  B0100010
};
int y[7] = {
  B0000000,
  B0100010,
  B0100010,
  B0011110,
  B0000010,
  B0111100,
  B0000000
};
int z[7] = {
  B0000000,
  B0000000,
  B0111110,
  B0000100,
  B0001000,
  B0010000,
  B0111110
};
int bitcoin1[7] = {
  B0000000,
  B0001100,
  B1111110,
  B0101101,
  B0101101,
  B0101101,
  B0111110
};
int bitcoin2[7] = {
  B0111110,
  B0101101,
  B0101101,
  B0101101,
  B1111110,
  B0001100,
  B0000000
};
int dollar[7] = {
  B0001000,
  B0111110,
  B0100000,
  B0111110,
  B0000010,
  B0111110,
  B0001000
};
int euro[7] = {
  B0001110,
  B0010000,
  B0111100,
  B0010000,
  B0111100,
  B0010000,
  B0001110
};
int dot[7] = {
  B0000000,
  B0000000,
  B0000000,
  B0000000,
  B0000000,
  B0000000,
  B0100000
};

int zero_s[7] = {
  B0000000,
  B0000000,
  B0011100,
  B0010100,
  B0010100,
  B0010100,
  B0011100
};
int one_s[7] = {
  B0000000,
  B0000000,
  B0000100,
  B0001100,
  B0000100,
  B0000100,
  B0000100
};
int two_s[7] = {
  B0000000,
  B0000000,
  B0011100,
  B0000100,
  B0011100,
  B0010000,
  B0011100
};
int three_s[7] = {
  B0000000,
  B0000000,
  B0011100,
  B0000100,
  B0011100,
  B0000100,
  B0011100
};
int four_s[7] = {
  B0000000,
  B0000000,
  B0010100,
  B0010100,
  B0011100,
  B0000100,
  B0000100
};
int five_s[7] = {
  B0000000,
  B0000000,
  B0011100,
  B0010000,
  B0011100,
  B0000100,
  B0011100
};
int six_s[7] = {
  B0000000,
  B0000000,
  B0011100,
  B0010000,
  B0011100,
  B0010100,
  B0011100
};
int seven_s[7] = {
  B0000000,
  B0000000,
  B0011100,
  B0000100,
  B0000100,
  B0001000,
  B0001000
};
int eight_s[7] = {
  B0000000,
  B0000000,
  B0011100,
  B0010100,
  B0011100,
  B0010100,
  B0011100
};
int nine_s[7] = {
  B0000000,
  B0000000,
  B0011100,
  B0010100,
  B0011100,
  B0000100,
  B0011100
};
int dot_s[7] = {
  B0000000,
  B0000000,
  B0000000,
  B0000000,
  B0000000,
  B0000000,
  B0001000
};
int dollar_s[7] = {
  B0001000,
  B0011100,
  B0010000,
  B0011100,
  B0000100,
  B0011100,
  B0001000
};
int euro_s[7] = {
  B0011100,
  B0010000,
  B0111000,
  B0010000,
  B0111000,
  B0010000,
  B0011100
};

char mat_new[512] = {
  'b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b',
  'b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b',
  'b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b',
  'b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b',
  'b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b',
  'b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b',
  'b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b',
  'b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b',
  'b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b',
  'b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b',
  'b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b',
  'b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b',
  'b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b',
  'b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b',
  'b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b',
  'b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b','b'
};





int color = 0;
int font = 0;
void drawletter(char letter, int X, int Y) {
  xpos = X;
  ypos = Y;
  if(font == 0) {
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
      case '$': draw_final(dollar);break;
      case 'E': draw_final(euro);break;
      case '.': draw_final(dot);break;
      default: break;
    }
  }
  if(font == 1) {
    switch(letter) {
      case '0': draw_final(zero_s);break;
      case '1': draw_final(one_s);break;
      case '2': draw_final(two_s);break;
      case '3': draw_final(three_s);break;
      case '4': draw_final(four_s);break;
      case '5': draw_final(five_s);break;
      case '6': draw_final(six_s);break;
      case '7': draw_final(seven_s);break;
      case '8': draw_final(eight_s);break;
      case '9': draw_final(nine_s);break;
      case '.': draw_final(dot_s);break;
      case 'E': draw_final(euro_s);break;
      case '$': draw_final(dollar_s);break;
                //unkown char should be here ...
      default: break;
    }
  }
}

void draw_final(int array[7]) {
  int final_array[7][7];
  for (int i=0; i<=6; i++) {
    int mask = B1000000;
    for (int j=0; j<=6; j++) {
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
  for (int k=0; k<=6; k++) {
    for (int l=0; l<=6; l++) {
      if(final_array[l][k] == 1) {
        if(color == 0) {
          new_plot(k+xpos,l+ypos,0);
        }
        if(color == 1) {
          new_plot(k+xpos,l+ypos,1);
        }
        if(color == 2) {
          new_plot(k+xpos,l+ypos,2);
        }
      }
    }
  }
}
void new_plot(int xpos, int ypos, int color) {
  if(color == 0) {
    mat_new[xpos  +32 * ypos] = 'r';
  }
  if(color == 1) {
    mat_new[xpos +32 * ypos] = 'g';
  }
  if(color == 2) {
    mat_new[xpos +32 * ypos] = 'o';
  }
}

void new_render() {
  for(int y=0; y<16; y = y++) {
    for(int x=0; x<32; x++) {
      if(mat_new[y * 32 + x] == 'r') {
        matrix->plot(x,y,RED);
      }
      if(mat_new[y * 32 + x] == 'g') {
        matrix->plot(x,y,GREEN);
      }
      if(mat_new[y * 32 + x] == 'o') {
        matrix->plot(x,y,ORANGE);
      }
      if(mat_new[y * 32 + x] == 'b') {
        matrix->plot(x,y,BLACK);
      }
    }
  }
  for(int i=0; i<512; i++) {
    mat_new[i] = 'b';
  }
  matrix->render();
}

int cursor_posx = 0;
int cursor_posy = 0;

String buffer = "";

void loop()
{
  if (Serial.available()) {
    char input = Serial.read();
    if(input == '\n') {
      if(buffer.substring(0,2) == "w=") {
        String position = buffer.substring(buffer.indexOf('=')+1,buffer.indexOf(':'));

        cursor_posx = position.substring(0,2).toInt();
        cursor_posy = position.substring(2,4).toInt();

        for(int i=buffer.indexOf(':')+1;i <= buffer.length();i++) {
          char letter = buffer.charAt(i);
          drawletter(letter, cursor_posx, cursor_posy);
          if(font == 0) {
            if(letter == '.')
              cursor_posx = cursor_posx + 2;
            else
              cursor_posx = cursor_posx + 6;
          }
          if(font == 1) {
            if(letter == '.')
              cursor_posx = cursor_posx + 2;
            else
              cursor_posx = cursor_posx + 4;
          }
        }
      }
      if(buffer.substring(0,2) == "W=") {
        String position = buffer.substring(buffer.indexOf('=')+1,buffer.indexOf(':'));

        cursor_posx = position.substring(0,2).toInt();
        cursor_posy = position.substring(2,4).toInt();

        for(int i=buffer.indexOf(':')+1;i <= buffer.length();i++) {
          char letter = buffer.charAt(i);
          drawletter(letter, cursor_posx, cursor_posy);
          if(font == 0) {
            if(letter == '.')
              cursor_posx = cursor_posx - 2;
            else
              cursor_posx = cursor_posx - 6;
          }
          if(font == 1) {
            if(letter == '1')
              cursor_posx = cursor_posx - 3;
            else
              cursor_posx = cursor_posx - 4;
          }
        }
      }
      if(buffer.substring(0,2) == "c=") {
        String col = buffer.substring(buffer.indexOf('=')+1,buffer.length());
        if(col == "red") {
          color = 0;
        }
        if(col == "green") {
          color = 1;
        }
        if(col == "orange") {
          color = 2;
        }
      }
      if(buffer.substring(0,2) == "N=") {
        for(int i=0;i<32;i++) {
          for(int j=0;j<16;j++) {
            int rnd = random(0,3);
            if(rnd == 0)
              matrix->plot(i,j,RED);
            if(rnd == 1)
              matrix->plot(i,j,GREEN);
            if(rnd == 2)
              matrix->plot(i,j,ORANGE);
          }
          matrix->render();
        }
      }
      if(buffer.substring(0,2) == "C=") {
        new_render();
      }
      if(buffer.substring(0,2) == "f=") {
        String f = buffer.substring(buffer.indexOf('=')+1,buffer.length());
        if(f == "normal") {
          font = 0;
        }
        if(f == "small") {
          font = 1;
        }
      }
      if(buffer.substring(0,2) == "b=") {
          drawletter('A', 0, 1);
          drawletter('B', 0, 8);
      }
      buffer = "";
    }
    else {
      buffer += input;
    }
  }
}
