package com.intelli.qingfeng.util;

import java.util.ArrayList;
import java.util.List;

import android.app.Activity;

public class ActivityCollectorUtil {
	
	public static List<Activity> activityList = new ArrayList<Activity>();

	public static void addActivity(Activity activity) {
		if (!activityList.contains(activity)) {
			activityList.add(activity);
		}
	}

	public static void removeActivity(Activity activity) {
		activityList.remove(activity);
	}

	public static void finishAll() {
		for (Activity activity : activityList) {
			if (!activity.isFinishing()) {
				activity.finish();
			}
		}
	}
	
}
