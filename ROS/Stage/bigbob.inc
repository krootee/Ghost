define bigbob position
(
      size [1.25 1 1]

      # the shape of Bigbob

      block
      (
            points 6
            point[5] [0 0]
            point[4] [0 1]
            point[3] [0.75 1]
            point[2] [1 0.75]
            point[1] [1 0.25]
            point[0] [0.75 0]
            z [0 1]
      )

      block
      (
            points 4
            point[3] [1 0.75]
            point[2] [1.25 0.75]
            point[1] [1.25 0.625]
            point[0] [1 0.625]
            z [0 0.5]
      )

      block
      (
            points 4
            point[3] [1 0.375]
            point[2] [1.25 0.375]
            point[1] [1.25 0.25]
            point[0] [1 0.25]
            z [0 0.5]
      )

      drive "car"

      bigbobs_sonars()
)

define bigbobs_sonar sensor
(
    # define the size of each transducer [xsize ysize zsize] in meters
    size [0.01 0.05 0.01 ]
    # define the range bounds [min max]
    range [0.3 2.0]
    # define the angular field of view in degrees
    fov 10
    # define the color that ranges are drawn in the gui
    color_rgba [ 0 1 0 1 ]
)

define bigbobs_sonars ranger
(
  # one line for each sonar [xpos ypos zpos heading]
  bigbobs_sonar( pose [ 0.75 0.1875 0 0]) # fr left tooth
  bigbobs_sonar( pose [ 0.75 -0.1875 0 0]) # fr right tooth
  bigbobs_sonar( pose [ 0.25 0.5 0 30]) # left corner
  bigbobs_sonar( pose [ 0.25 -0.5 0 -30]) # right corner
)
