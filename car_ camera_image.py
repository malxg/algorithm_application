#实现视频接受 html 
<script type="text/javascript">
    var imageNr = 0; // 图片的索引号
    var finished = new Array(); // 下载图片的队列
    var paused = false; //
    function createImageLayer() {
      var img = new Image();
      img.style.position = "absolute";
      img.style.zIndex = -1;
      img.onload = imageOnload;
      img.onclick = imageOnclick;
         //填你对应的ip和端口
      img.src = "http://172.19.8.176:8080/?action=snapshot&n=" + (++imageNr);
      var webcam = document.getElementById("webcam");
      webcam.insertBefore(img, webcam.firstChild);
    }