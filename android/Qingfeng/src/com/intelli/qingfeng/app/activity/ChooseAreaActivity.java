package com.intelli.qingfeng.app.activity;

import java.util.ArrayList;
import java.util.List;

import com.intelli.qingfeng.app.common.BaseActivity;
import com.intelli.qingfeng.app.dao.QingfengDB;
import com.intelli.qingfeng.app.model.City;
import com.intelli.qingfeng.app.model.County;
import com.intelli.qingfeng.app.model.Province;

import android.app.ProgressDialog;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.TextView;

public class ChooseAreaActivity extends BaseActivity {
	
	public static final int LEVEL_PROVINCE = 0;
	public static final int LEVEL_CITY = 1;
	public static final int LEVEL_COUNTY = 2;
	
	private ProgressDialog progressDialog;
	private TextView titleText;
	private ListView listView;
	
	private ArrayAdapter<String> adapter;
	
	private QingfengDB qingfengDB;
	private List<String> dataList = new ArrayList<String>();
	
	private List<Province> provinceList = new ArrayList<Province>();
	private List<City> cityList = new ArrayList<City>();
	private List<County> countyList = new ArrayList<County>();
	
//	private 

}
