<?php
    $input = trim(fgets(STDIN));
    $input = explode(" ", $input);
    $e = $input[0];
    $v = $input[1];
    $t = $input[2];
    $min = 9999999999;

    $node = array();
    $edge = array();
    for($i = 0 ; $i < $v ; $i++)
    {
        $node[] =9999999999;
        $edge[] = array();
        for($j = 0 ; $j < $v ; $j++)
        {
            $edge[$i][] = -1;
        }
    }

    for($i = 0 ; $i < $e ; $i++)
    {
        $input = trim(fgets(STDIN));
        $input = explode(" ", $input);
        $edge[$input[0]][$input[1]] = $input[2];
        $edge[$input[1]][$input[0]] = $input[2];
    }


    Dijkstra($e, $v ,$t);
    echo $min;

    function Dijkstra($e, $v, $t)
    {
        global $node;
        global $edge;
        global $min;

        $_To = array();
        $_To[] = 0;
        $node[0] = 0;
        $index = 0;


        while(count($_To) > 0)
        {
            $index = array_shift($_To);
            if($index == $t)
            {
                if($min > $node[$index]) $min = $node[$index];
            }

            for($i = 0 ; $i < $v ; $i++)
            {
                if($edge[$index][$i] >= 0)
                {
                    if($node[$i] > ($node[$index] + $edge[$index][$i]))
                    {

                        $node[$i] = ($node[$index] + $edge[$index][$i]);
                        $_To[] = $i;
                    }
                }
            }
        }
    }
?>
