package com.intelli.utils.test;

import com.intelli.general.MainActivity;
import com.intelli.utils.ActivityCollectorUtils;

import android.test.AndroidTestCase;
import junit.framework.Assert;

public class ActivityCollectorUtilsTest extends AndroidTestCase {

	@Override
	protected void setUp() throws Exception {
		// TODO Auto-generated method stub
		super.setUp();
	}
	
	public void testAddActivity() {
		Assert.assertEquals(0, ActivityCollectorUtils.activityList.size());
		MainActivity activity = new MainActivity();
		ActivityCollectorUtils.addActivity(activity);
		Assert.assertEquals(1, ActivityCollectorUtils.activityList.size());
		ActivityCollectorUtils.addActivity(activity);
		Assert.assertEquals(1, ActivityCollectorUtils.activityList.size());
	}

	@Override
	protected void tearDown() throws Exception {
		// TODO Auto-generated method stub
		super.tearDown();
	}

}
