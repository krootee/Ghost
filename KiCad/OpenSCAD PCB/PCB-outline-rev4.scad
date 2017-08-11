length = 63;
width = 43;
corner_length = 10;
corner_width = 10;

module corner() {
    cube([corner_length, corner_width, 1]);
}

cube([length,width,1]);