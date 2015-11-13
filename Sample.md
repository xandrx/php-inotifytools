
```
<?php
inotifytools_initialize();
$wd = inotifytools_watch_recursively('/tmp', IN_MOVE | IN_CLOSE_WRITE);
while (1){
while ($ev = inotifytools_next_event(1)) { 
  echo $ev['name']."\n"; // other field in $ev: mask wd cookie
}
sleep(1);//try write sth in /tmp dir
}
?>
```