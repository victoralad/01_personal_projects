package com.example.firstapp;


import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;


import java.util.Random;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //pick random numbers
        Random randy = new Random();
        int rand1 = randy.nextInt(10);
        int rand2 = randy.nextInt(10);

        Button lbutt = (Button) findViewById(R.id.left_button);
        lbutt.setText(Integer.toString(rand1));
        Button rbutt = (Button) findViewById(R.id.right_button);
        rbutt.setText(Integer.toString(rand2));
    }

    public void leftButtonClick(View view) {
    }

    public void rightButtonClick(View view) {
    }
}
