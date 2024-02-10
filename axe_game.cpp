#include "raylib.h"

int main()
{

    //Dimensões da janela    
    int width=1024,height=720;

   

    //Cordenadas do Circulo
    int cx=512,
    cy=310,
    radius=25,
    //Bordas do Circulo (posso sustituir o {}, por =)
    left_cx{cx - radius},
    right_cx{cx + radius},
    up_cy{cy - radius},
    down_cy{cy + radius};
    
     //Cordenadas do retângulo
    int rx=300,
    ry=0,
    largura=50,
    altura=50,
    direction=10,
    left_rx = rx,
    right_rx = rx + largura,
    up_ry = ry,
    down_ry = ry + altura;

     //boolean
    bool collision_with_axe = (down_ry >= down_cy) && (up_ry <= up_cy) && (left_rx <= right_cx) && (right_rx >= left_cx);

    //Definições Texto
    int tx=380,
    ty=300,
    tfont_size= 50;
    Color tcolor = RED;


 InitWindow(width,height,"Axe Game");


SetTargetFPS(60);
while(WindowShouldClose() == false){
    BeginDrawing();
    ClearBackground(WHITE);

    if (collision_with_axe == true){
      DrawText("Game Over!",tx,ty,tfont_size,tcolor);
     
    }else{

    //update as bordas

    //circulo
    left_cx = cx - radius;
    right_cx = cx + radius;
    up_cy = cy - radius;
    down_cy = cy + radius;
    
    //retângulo
    left_rx = rx;
    right_rx = rx + largura;
    up_ry = ry;
    down_ry = ry + altura;

    //update colisão com retângulo
     collision_with_axe = (down_ry >= up_cy) && (up_ry <= down_cy) && (left_rx <= right_cx) && (right_rx >= left_cx);


    DrawCircle(cx,cy,radius,BLUE);
    DrawRectangle(rx,ry,largura,altura,RED);

    //mover axe
    ry += direction;
    if(ry > height || ry < 0){
      direction = -direction;
    }

  
    

    //Comandos
    if (IsKeyDown(KEY_D) && cx < width){
      cx += 10;
    }
    if (IsKeyDown(KEY_A) && cx > 0){
      cx -= 10;
    }
    }
    
    EndDrawing();
       

}
}



