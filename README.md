# Hazel Engine

The Hazel Engine is a project based on the Hazel Engine by [@TheCherno](https://github.com/TheCherno/). I'm following the tutorial videos on his [YouTube Channel](https://www.youtube.com/user/TheChernoProject) to learn a more about C++, graphics, and software engineering and design. 

This varient of Hazel has only been tested on MacOS and most likely will not work for Linux or Windows. Since OpenGL is depreciated on MacOS, version 4.1 is used. Additional platform-support may be added in the future.

### On Mac
Open ```Terminal``` and run the following script:
```
git clone --recursive https://github.com/brolgedu/Hazel ~/dev/Hazel && 
mkdir ~/dev/Hazel/build && cd ~/dev/Hazel/build && 
cmake ../ && cmake --build ./ && ./SandboxApp
```

### Camera controls
**W** - up 

**S** - down

**A** - left

**D** - right

**Q** - rotate right (if enabled)

**E** - rotate left (if enabled) 

**Mouse_Scroll** - zoom in/out  
**Mouse_Button_Middle** - reset 
