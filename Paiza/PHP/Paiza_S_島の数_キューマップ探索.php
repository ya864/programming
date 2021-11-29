<?php
    $input = trim(fgets(STDIN));
    $input = explode(" ", $input);
    $n = $input[0];
    $m = $input[1];

    $map = array();
    for($i = 0 ; $i < $m; $i++)
    {
        $input = trim(fgets(STDIN));
        $input = explode(" ", $input);
        $map[] = $input;
    }
    $cnt = 0;

    for($i = 0 ; $i < $m ; $i++)
    {
        for($j = 0 ; $j < $n ; $j++)
        {
            if($map[$i][$j] == 1)
            {
                $map[$i][$j] = -1;
                islands($i, $j);
                $cnt++;
            }
        }
    }

    echo $cnt;

    function islands($i, $j)
    {
        global $map;
        global $n;
        global $m;

        $xpos = array();
        $ypos = array();
        $xpos[] = $i;
        $ypos[] = $j;
        $x = 0;
        $y = 0;

        /*

        */
        while(count($xpos) > 0)
        {
            $x = array_shift($xpos);
            $y = array_shift($ypos);


            if($x > 0 && $map[$x-1][$y] == 1)
            {
                $map[$x-1][$y] = -1;
                $xpos[] = $x-1;
                $ypos[] = $y;
            }
            if($x < $m-1 && $map[$x+1][$y] == 1)
            {
                $map[$x+1][$y] = -1;
                $xpos[] = $x+1;
                $ypos[] = $y;
            }
            if($y > 0 && $map[$x][$y-1] == 1)
            {
                $map[$x][$y-1] = -1;
                $xpos[] = $x;
                $ypos[] = $y-1;
            }
            if($y < $n-1 && $map[$x][$y+1] == 1)
            {
                $map[$x][$y+1] = -1;
                $xpos[] = $x;
                $ypos[] = $y+1;
            }
        }
    }
?>
