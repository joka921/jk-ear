package org.qtproject.example.mediaplayer;

import android.media.MediaPlayer;
import android.os.Bundle;
import android.net.Uri;
import java.io.IOException;

public class javamediaplayer extends org.qtproject.qt5.android.bindings.QtActivity
{
    private static javamediaplayer m_instance;
    private static MediaPlayer mediaPlayer;

    public javamediaplayer(String filename)
    {
        m_instance = this;



    }

    public static void create(String filename) {
       m_instance.mediaPlayer = new MediaPlayer();
       try {

       m_instance.mediaPlayer.setDataSource("filename.bla");
       m_instance.mediaPlayer.prepare();
   } catch (IOException e) {
          e.printStackTrace();
      } catch (IllegalStateException e) {
          e.printStackTrace();
      }
   }
    public static void play()
    {
        try {
       if(!m_instance.mediaPlayer.isPlaying()){
         m_instance.mediaPlayer.start();
     }
 }catch (IllegalStateException e) {
     e.printStackTrace();
 }

}

    public static void stop()
    {
     /*   mediaPlayer.pause();
        mediaPlayer.seekTo(0);*/
        //mediaPlayer.prepare();

    }

}

