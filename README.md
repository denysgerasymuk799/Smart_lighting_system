# Smart Lighting System

![](https://img.shields.io/badge/-status:wip-5319e7.svg)
![](https://img.shields.io/github/license/damoklov/nasa.svg)
![](https://img.shields.io/github/languages/code-size/denysgerasymuk799/Smart_lighting_system.svg)
![](https://img.shields.io/github/last-commit/denysgerasymuk799/Smart_lighting_system.svg)
    
## Description: :sparkler:

**The main target** of the project is to design a dynamic system of lighting devices on the soft and hard level,
which have special functionality and can be controlled with the main board or your smartphone via Bluetooth.

This  project  demonstrates how  to  transform  BLE  Pioneer  Kits  with  PSoC  4  BLE  into  nodes  of  a  **Mesh  Network** 
and  relay common  data  over  that  network  using  flooding mechanism.  The system  employs  connection  method,
where  a  BLE connection  is  made  between  two  nodes  before  data  is  transferred.
    
Once  the  data  has  been  received  by  a  node,  the  node switches GAP role to connect to other nodes and relay the same data.
The data relayed in this project is of **RGB LED color** and  **intensity  control**  and  the  Mesh  Network  allows  it
to  be  relayed  to  each  node  in  that  network. The  project  can  be  **easily modified to relay any other form of data.**

 
Based on such approach, we have developed the following **functionality**:

1. **Auto reassignment** of the main control board: in the main mode, there is the main control board, which initialises changing the color
and its spread throughout the Mesh system. Furthermore, if the main board disappears, so the system lights up red color
and auto reassignment of the main control board is starting -- as the result one of the peripherals becomes the main control board.

2. **Synchronisation with music**: the system is able to make the lighting show by changing the color and brightness
depending on the music bits.
 
3. Switching the system on/off and **switching** between modes **with clapping**.

4. **Switching the role** (from Central to Peripheral or vice versa) pushing the button.

5. **Code Morse**: realisation of the well-known code Morse with blinking and changing brightness of lights.    


**Based on** Cypress ![Mesh_Flood project](https://github.com/Cypresssemiconductorco/PSoC-4-BLE/tree/master/100_Projects_in_100_Days/Day049_BLE_Mesh_Flood)


## Description of each folder :pushpin:

- Mesh_Flood_PSoC4BLE_Original.cydsn -- an original code of Cypress Mesh_Flood project;

- Mesh_Flood_Main_Auto_Reassignment.cydsn -- a code with the function of auto reassignment of the main control board;

# License:
[MIT](https://choosealicense.com/licenses/mit/)
