package com.intelli.qingfeng.app.util;

import android.app.Application;
import android.content.Context;

public class ContextUtil extends Application {

	private static Context context;

	@Override
	public void onCreate() {
		super.onCreate();
		context = this.getApplicationContext();
	}

	public static Context getContext() {
		return context;
	}

}
