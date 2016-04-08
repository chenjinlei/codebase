package com.example.activitytest;

import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.Window;
import android.widget.Button;

public class SecondActivity extends BaseActivity {
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		requestWindowFeature(Window.FEATURE_NO_TITLE);
		setContentView(R.layout.second_layout);
		
//		Intent in = getIntent();
//		String data = in.getStringExtra("extra_data");
//		Log.d("SecondActivity", data);
		Log.d("SecondActivity", "Task id is " + getTaskId());
		Button button = (Button) findViewById(R.id.button_2);
		button.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) {
//				Intent intent = new Intent("android.intent.action.MAIN");
//				intent.addCategory("android.intent.category.LAUNCHER");
//				startActivity(intent);
				// 传输数据
//				Intent intent = getIntent();
//				String data = intent.getStringExtra("extra_data");
//				Log.d("FirstActivity", data);
//				if (data.equals("1")) {
//					Intent out = new Intent();
//					out.putExtra("ret", "Hello FirstActivity");
//					setResult(RESULT_OK, out);
//					finish();
//				}
				Intent in = new Intent(SecondActivity.this, ThirdActivity.class);
				startActivity(in);
			}
		});
		
		// for best practice
		Intent in = getIntent();
		String firstName = in.getStringExtra("param1");
		String lastName = in.getStringExtra("param2");
		Log.d("SecondActivity", firstName + "·" + lastName);
	}
	
	@Override
	protected void onDestroy() {
		super.onDestroy();
		Log.d("SecondActivity", "onDestroy");
	}
	
	public static void actionStart(Context context, String firstName, String lastName) {
		Intent intent = new Intent(context, SecondActivity.class);
		intent.putExtra("param1", firstName);
		intent.putExtra("param2", lastName);
		context.startActivity(intent);
	}
}
