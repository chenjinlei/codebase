package com.intelli.activity;

import com.intelli.utils.ActivityCollectorUtils;

import android.app.Activity;
import android.os.Bundle;

public class BaseActivity extends Activity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		
		super.onCreate(savedInstanceState);
		ActivityCollectorUtils.addActivity(this);
	}

	@Override
	protected void onDestroy() {
		
		super.onDestroy();
		ActivityCollectorUtils.removeActivity(this);
	}
	
}
