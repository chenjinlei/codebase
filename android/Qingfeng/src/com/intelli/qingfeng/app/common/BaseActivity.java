package com.intelli.qingfeng.app.common;


import com.intelli.qingfeng.app.util.ActivityCollectorUtil;

import android.app.Activity;
import android.os.Bundle;

public class BaseActivity extends Activity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {

		super.onCreate(savedInstanceState);
		ActivityCollectorUtil.addActivity(this);
	}

	@Override
	protected void onDestroy() {

		super.onDestroy();
		ActivityCollectorUtil.removeActivity(this);
	}

}
