<?php
    // pi()で取得するのが王道だが、桁が足らなかったので文字列として扱う
    $ans = "3.141592653589793";
    $n = trim(fgets(STDIN));
    // 指定された桁数だけ残すように、文字全体から15-指定数だけ削除
    $replace = substr($ans, 0, strlen($ans)-(15-$n));
    echo $replace;
?>
