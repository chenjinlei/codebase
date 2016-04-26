package com.intelli.qingfeng.activity;

import java.util.ArrayList;
import java.util.List;

import com.intelli.qingfeng.R;
import com.intelli.qingfeng.common.BaseActivity;
import com.intelli.qingfeng.dao.QingfengDB;
import com.intelli.qingfeng.model.City;
import com.intelli.qingfeng.model.County;
import com.intelli.qingfeng.model.Province;
import com.intelli.qingfeng.util.HttpCallbackListener;
import com.intelli.qingfeng.util.HttpUtil;
import com.intelli.qingfeng.util.Utility;

import android.app.ProgressDialog;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.preference.PreferenceManager;
import android.text.TextUtils;
import android.view.View;
import android.view.Window;
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemClickListener;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;

public class ChooseAreaActivity extends BaseActivity implements OnItemClickListener {

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

	private Province selectedProvince;
	private City selectedCity;
	// private County selectedCounty;
	private int currentLevel;

	private boolean isFromWeatherActivity;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);

		isFromWeatherActivity = getIntent().getBooleanExtra("from_weather_ activity", false);
		SharedPreferences prefs = PreferenceManager.getDefaultSharedPreferences(this);
		if (prefs.getBoolean("city_selected", false)) {
			Intent intent = new Intent(this, WeatherActivity.class);
			startActivity(intent);
			finish();
			return;
		}

		this.requestWindowFeature(Window.FEATURE_NO_TITLE);
		this.setContentView(R.layout.choose_area);

		listView = (ListView) this.findViewById(R.id.list_view);
		titleText = (TextView) this.findViewById(R.id.title_text);
		adapter = new ArrayAdapter<String>(this, android.R.layout.simple_list_item_1, dataList);

		listView.setAdapter(adapter);
		qingfengDB = QingfengDB.getInstance(ChooseAreaActivity.this);
		listView.setOnItemClickListener(this);

		queryProvinces();
	}

	@Override
	public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
		if (currentLevel == LEVEL_PROVINCE) {
			selectedProvince = provinceList.get(position);
			queryCities();
		} else if (currentLevel == LEVEL_CITY) {
			selectedCity = cityList.get(position);
			queryCounties();
		} else if (currentLevel == LEVEL_COUNTY) {
			String countyCode = countyList.get(position).getCountyCode();
			Intent intent = new Intent(this, WeatherActivity.class);
			intent.putExtra("county_code", countyCode);
			startActivity(intent);
			finish();
		}
	}

	private void queryProvinces() {
		provinceList = qingfengDB.loadProvinces();
		if (provinceList.size() > 0) {
			dataList.clear();
			for (Province p : provinceList) {
				dataList.add(p.getProvinceName());
			}
			adapter.notifyDataSetChanged();
			listView.setSelection(0);
			titleText.setText("中国");
			currentLevel = LEVEL_PROVINCE;
		} else {
			queryFromServer(null, "province");
		}
	}

	private void queryCities() {
		cityList = qingfengDB.loadCities(selectedProvince.getId());
		if (cityList.size() > 0) {
			dataList.clear();
			for (City c : cityList) {
				dataList.add(c.getCityName());
			}
			adapter.notifyDataSetChanged();
			listView.setSelection(0);
			titleText.setText(selectedProvince.getProvinceName());
			currentLevel = LEVEL_CITY;
		} else {
			queryFromServer(selectedProvince.getProvinceCode(), "city");
		}

	}

	private void queryCounties() {
		countyList = qingfengDB.loadCounties(selectedCity.getId());
		if (countyList.size() > 0) {
			dataList.clear();
			for (County c : countyList) {
				dataList.add(c.getCountyName());
			}
			adapter.notifyDataSetChanged();
			listView.setSelection(0);
			titleText.setText(selectedCity.getCityName());
			currentLevel = LEVEL_COUNTY;
		} else {
			queryFromServer(selectedCity.getCityCode(), "county");
		}
	}

	private void queryFromServer(String code, final String type) {
		String address;

		if (!TextUtils.isEmpty(code)) {
			address = "http://www.weather.com.cn/data/list3/city" + code + ".xml";
		} else {
			address = "http://www.weather.com.cn/data/list3/city.xml";
		}

		showProgressDialog();
		HttpUtil.sendHttpRequest(address, new HttpCallbackListener() {

			@Override
			public void onFinish(String response) {
				boolean result = false;
				if ("province".equals(type)) {
					result = Utility.handleProvincesResponse(qingfengDB, response);
				} else if ("city".equals(type)) {
					result = Utility.handleCitiesResponse(qingfengDB, response, selectedProvince.getId());
				} else if ("county".equals(type)) {
					result = Utility.handleCountiesResponse(qingfengDB, response, selectedCity.getId());
				}

				if (result) {
					runOnUiThread(new Runnable() {

						@Override
						public void run() {
							closeProgressDialog();
							if ("province".equals(type)) {
								queryProvinces();
							} else if ("city".equals(type)) {
								queryCities();
							} else if ("county".equals(type)) {
								queryCounties();
							}

						}
					});
				}

			}

			@Override
			public void onError(Exception e) {
				runOnUiThread(new Runnable() {

					@Override
					public void run() {
						closeProgressDialog();
						Toast.makeText(ChooseAreaActivity.this, "加载失败", Toast.LENGTH_SHORT).show();

					}
				});

			}
		});

	}

	private void showProgressDialog() {
		if (progressDialog == null) {
			progressDialog = new ProgressDialog(this);
			progressDialog.setMessage("正在加载...");
			progressDialog.setCanceledOnTouchOutside(false);

		}
		progressDialog.show();
	}

	private void closeProgressDialog() {
		if (progressDialog != null) {
			progressDialog.dismiss();
		}
	}

	@Override
	public void onBackPressed() {
		if (currentLevel == LEVEL_COUNTY) {
			queryCities();
		} else if (currentLevel == LEVEL_CITY) {
			queryProvinces();
		} else {
			if (isFromWeatherActivity) {
				Intent intent = new Intent(this, WeatherActivity.class);
				startActivity(intent);
			}
			finish();
		}
	}
}
