package com.example.activitytest;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.Window;
import android.widget.Button;
import android.widget.Toast;

public class FirstActivity extends BaseActivity {
	@Override
	protected void onCreate(Bundle savedInstance) {
		super.onCreate(savedInstance);
		requestWindowFeature(Window.FEATURE_NO_TITLE);
		setContentView(R.layout.first_layout);

		Log.d("FirstActivity", "Task id is " + getTaskId());
		Button button = (Button) findViewById(R.id.button_1);
		button.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) {
//				Toast.makeText(FirstActivity.this, "You clicked Button.", Toast.LENGTH_LONG).show();
				// 撤销活动页面
//				finish();
				// 显示意图
//				Intent intent = new Intent(FirstActivity.this, SecondActivity.class);
//				startActivity(intent);
				// 隐式意图
//				Intent intent = new Intent("com.example.activitytest.ACTION_START");
//				startActivity(intent);
				// 隐式意图
//				Intent intent = new Intent("com.example.activitytest.ACTION_START");
//				intent.addCategory("com.example.activitytest.MY_CATEGORY");
//				startActivity(intent);
				// 隐式意图－调用其他程序功能
//				Intent intent = new Intent(Intent.ACTION_VIEW);
//				intent.setData(Uri.parse("http://www.baidu.com"));
//				startActivity(intent);
				// 隐式意图－调用打电话
//				Intent intent = new Intent(Intent.ACTION_DIAL);
//				intent.setData(Uri.parse("tel:10086"));
//				startActivity(intent);
				// 往SecondActivity传递参数
//				String data = "Hello SecondActivity";
//				Intent intent = new Intent(FirstActivity.this, SecondActivity.class);
//				intent.putExtra("extra_data", data);
//				startActivity(intent);
				// 有返回值的启动Activity
//				Intent intent = new Intent(FirstActivity.this, SecondActivity.class);
//				intent.putExtra("extra_data", "1");
//				startActivityForResult(intent, 1);
				// 启动模式
				Intent intent = new Intent(FirstActivity.this, SecondActivity.class);
				SecondActivity.actionStart(FirstActivity.this, "James", "Chen");
				startActivity(intent);
			}
		});
		
	}
	
	@Override
	protected void onRestart() {
		super.onRestart();
		Log.d("FirstActivity", "onRestart");
	}
	
	@Override
	protected void onActivityResult(int requestCode, int resultCode, Intent data) {
		switch(requestCode) {
		case 1:
			if (RESULT_OK == resultCode) {
				String ret = data.getStringExtra("ret");
				Log.d("FirstActivity", ret);
			}
			break;
		default:
			break;
		}
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		super.onCreateOptionsMenu(menu);
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}

	@Override
	public boolean onOptionsItemSelected(MenuItem item) {
		super.onOptionsItemSelected(item);
		switch (item.getItemId()) {
		case R.id.add_item:
			Toast.makeText(getBaseContext(), "Add Item, yeah!", Toast.LENGTH_SHORT).show();
			break;
		case R.id.remove_item:
			Toast.makeText(getBaseContext(), "Remove Item, yeah!", Toast.LENGTH_SHORT).show();
			break;
		default:
		}
		return true;
	}
}
