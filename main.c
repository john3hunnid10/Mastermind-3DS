#include <stdio.h>
#include <string.h>
#include <3ds.h>

int main()
{
  // Initializations
  srvInit();        // services
  aptInit();        // applets
  hidInit(NULL);    // input
  gfxInitDefault(); // graphics
  gfxSet3D(false);  // stereoscopy (true == on / false == off)
  u32 kDown;        // keys down
  u32 kHeld;        // keys pressed
  u32 kUp;          // keys up
  u8* fbTopLeft;    // top left screen's framebuffer
  u8* fbTopRight;   // top right screen's framebuffer
  u8* fbBottom;     // bottom screen's framebuffer
    
  // Main loop
  //
  gfxInitDefault();

  while (aptMainLoop())
  {

    // Wait for next frame
    gspWaitForVBlank();

    // Read which buttons are currently pressed or not
    hidScanInput();
    kDown = hidKeysDown();
    kHeld = hidKeysHeld();
    kUp = hidKeysUp();

    // If START button is pressed, break loop and quit
    if (kDown & KEY_START){
      break;
    }
    
    // Reset framebuffers
    fbTopLeft = gfxGetFramebuffer(GFX_TOP, GFX_LEFT, NULL, NULL);
    fbTopRight = gfxGetFramebuffer(GFX_TOP, GFX_RIGHT, NULL, NULL);
    fbBottom = gfxGetFramebuffer(GFX_BOTTOM, 0, NULL, NULL);
    memset(fbTopLeft, 0, 240 * 400 * 3);
    memset(fbTopRight, 0, 240 * 400 * 3);
    memset(fbBottom, 0, 240 * 320 * 3);


    /** Your code starts here **/
    
    
    
    /** End of your code **/

    
    // Flush and swap framebuffers
    gfxFlushBuffers();
    gfxSwapBuffers();
  }

  // Exit
  gfxExit();
  hidExit();
  aptExit();
  srvExit();

  // Return to hbmenu
  return 0;
}
int isValidGuess(const char* guess){
    for (int i=0; i<4; i++){
        if(strchr(guess+i, guess[i]) != NULL)
            return 0; 
        if(guess[i]!='X'&&guess[i]!='R'&&guess[i]!='A'&&guess[i]!='B'&&guess[i]!='L'&&guess[i]!='Y')
            return 0;
    }
    return 1;
}
int isInArray(char array[], int size, char value) {
    if(size==1){
        return 0;
    }
    for(int i=0; i<size; i++) {
        if(array[i]==value) {
            return 1;
        }
    }
    return 0;
}