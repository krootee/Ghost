$fn=100;

/*
 * Material: Biltema, 4mm Plexiglass
 * Laser cutter settings: 10mm/s 100% power
 */

module sensor()
{
    width = 8;
    scaleFactor = 1.18;
    
    scale(scaleFactor)
    translate([0,-2.5,-5])
    union() {
        cube([5.5,5,10]);
        translate([5,-1.5,-3]) cube([1,width,19]);
    }
}

module curve(radius, width)
{
    difference()
    {
        linear_extrude(height=3) circle(radius);
        linear_extrude(height=3) circle(radius-width);
        translate([-50,0,0]) cube([100,150,50], center=true);
       
    }
}

module part(includeSensorHoles)
{
    difference() 
    {
        curve(radius=33, width=13);
    
        if (includeSensorHoles)
            for (a = [-75 : 25 : 75])
                rotate(a) translate([30-12, 0, 0]) sensor();
    }
}

projection(cut=false) 
difference()
{
    part(true);
    for (i = [-30 : -60 : -150])
        rotate(i)
        translate([0,29,-5]) cylinder(r=1.53, h=200);
}
