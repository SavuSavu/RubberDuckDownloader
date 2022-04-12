// This only works in Windows when ENG(US) is selected 
#include <Arduino.h>
#include <Keyboard.h>


String createDownload()
{
    String list[] = {"https://github.com/microsoft/vscode/archive/refs/heads/main.zip"};
    String command = " curl -LJO ";

    String finalCommand = "";
    for(int x = 0; x < (sizeof(list) / sizeof(list[0]));x++)
    {
        finalCommand = finalCommand + command + list[x] + " && ";    

    }

    Serial.print(finalCommand);

    return finalCommand;
}


void setup()
{
  delay(1000);
    String final = createDownload();
    delay(1000);
    Serial.begin(9600);
    delay(100);
    
    Serial.print("Initializing the keyboard");
    //Beginning the stream
    Keyboard.begin();
    delay(1000);

    // Open "Run Application"
    Serial.print("Pressing windows key");
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press('r');
    delay(100);
    Keyboard.releaseAll();
    delay(100);

    //Opening cmd
    Keyboard.print("cmd");
    delay(200);
    Keyboard.write(KEY_RETURN);
    delay(1000);

    //Changing dir to downloads
    Keyboard.print("cd C:\\Users\\%USERNAME%\\Downloads");
    delay(100);
    Keyboard.write(KEY_RETURN);
    delay(100);
    //Creating a new dir
    Keyboard.print("mkdir AppsToInstall");
    delay(100);
    Keyboard.write(KEY_RETURN);
    delay(100);
    //Changin dir to AppsToInstall
    Keyboard.print("cd AppsToInstall");
    delay(100);
    Keyboard.write(KEY_RETURN);

    //Start the download proces     
    Keyboard.print(createDownload());
    Keyboard.write(KEY_RETURN);


    
}



// Unused
void loop() {}
