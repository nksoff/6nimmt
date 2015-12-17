<?php

$cards = range(1, 104);
shuffle($cards);

$sub = array();
$sub1 = array();
$sub2 = array();
for($i = 0; $i < 4; $i++) {
    $sub[] = $cards[$i];
}
for($i = 4; $i < 14; $i++) {
    $sub1[] = $cards[$i];
}
for($i = 14; $i < 24; $i++) {
    $sub2[] = $cards[$i];
}
sort($sub);
sort($sub1);
sort($sub2);

for($i = 0; $i < 4; $i++) {
    if($i > 0) {
        echo '|'; 
    }
    echo $sub[$i];
}

echo '=';

for($i = 0; $i < 10; $i++) {
    if($i > 0) {
        echo '|'; 
    }
    echo $sub1[$i];
}

echo '=';

for($i = 0; $i < 10; $i++) {
    if($i > 0) {
        echo '|'; 
    }
    echo $sub2[$i];
}

?>
