package com.intelli.qingfeng.app.dao;

import java.util.ArrayList;
import java.util.List;

import com.intelli.qingfeng.app.helper.QingfengOpenHelper;
import com.intelli.qingfeng.app.model.City;
import com.intelli.qingfeng.app.model.County;
import com.intelli.qingfeng.app.model.Province;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;

public class QingfengDB {

	/**
	 * 数据库名
	 */
	public static final String DB_NAME = "qingfeng";

	/**
	 * 数据库版本
	 */
	public static final int VERSION = 1;
	private static QingfengDB qingfengDB;
	private SQLiteDatabase db;

	/**
	 * 将构造方法私有化
	 */
	private QingfengDB(Context context) {
		QingfengOpenHelper dbHelper = new QingfengOpenHelper(context, DB_NAME, null, VERSION);
		db = dbHelper.getWritableDatabase();
	}

	/**
	 * 获取QingfengDB的实例
	 */
	public synchronized static QingfengDB getInstance(Context context) {
		if (qingfengDB == null)
			qingfengDB = new QingfengDB(context);
		return qingfengDB;

	}

	/**
	 * 将Province实例存储到数据库。
	 */
	public void saveProvince(Province province) {
		if (province != null) {
			ContentValues values = new ContentValues();
			values.put("province_name", province.getProvinceName());
			values.put("province_code", province.getProvinceCode());
			db.insert("Province", null, values);
		}
		
	}

	/**
	 * 从数据库读取全国所有的省份信息。
	 */
	public List<Province> loadProvinces() {
		List<Province> list = new ArrayList<Province>();
		Cursor cursor = db.query("Province", null, null, null, null, null, null);
		if (cursor.moveToFirst()) {
			do {
				Province province = new Province();
				province.setId(cursor.getInt(cursor.getColumnIndexOrThrow("id")));
				province.setProvinceCode(cursor.getString(cursor.getColumnIndexOrThrow("province_code")));
				province.setProvinceName(cursor.getString(cursor.getColumnIndexOrThrow("province_name")));
				list.add(province);
			} while (cursor.moveToNext());
		}
		return list;
	}

	/**
	 * 将City实例存储到数据库。
	 */
	public void saveCity(City city) {
		if (city != null) {
			ContentValues values = new ContentValues();
			values.put("city_name", city.getCityName());
			values.put("city_code", city.getCityCode());
			values.put("province_id", city.getProvinceId());
			db.insert("City", null, values);
		}
		
	}

	/**
	 * 从数据库读取某省下所有的城市信息。
	 */
	public List<City> loadCities(int provinceId) {
		List<City> list = new ArrayList<City>();
		Cursor cursor = db.query("City", null, "province_id = ?", new String[] { Integer.toString(provinceId) }, null,
				null, null);
		if (cursor.moveToFirst()) {
			do {
				City city = new City();
				city.setId(cursor.getInt(cursor.getColumnIndexOrThrow("id")));
				city.setCityCode(cursor.getString(cursor.getColumnIndexOrThrow("city_code")));
				city.setCityName(cursor.getString(cursor.getColumnIndexOrThrow("city_name")));
				city.setProvinceId(cursor.getInt(cursor.getColumnIndexOrThrow("province_id")));
				list.add(city);
			} while (cursor.moveToNext());
		}
		return list;
	}

	/**
	 * 将County实例存储到数据库。
	 */
	public void saveCounty(County county) {
		if (county != null) {
			ContentValues values = new ContentValues();
			values.put("county_code", county.getCountyCode());
			values.put("county_name", county.getCountyName());
			values.put("city_id", county.getCityId());
			db.insert("County", null, values);
		}
		
	}

	/**
	 * 从数据库读取某城市下所有的县信息。
	 */
	public List<County> loadCounties(int cityId) {
		List<County> list = new ArrayList<County>();
		Cursor cursor = db.query("County", null, "city_id = ?", new String[] { Integer.toString(cityId) }, null, null,
				null);

		if (cursor.moveToFirst()) {
			do {
				County county = new County();
				county.setCountyCode(cursor.getString(cursor.getColumnIndexOrThrow("county_code")));
				county.setCountyName(cursor.getString(cursor.getColumnIndexOrThrow("county_name")));
				county.setCityId(cursor.getInt(cursor.getColumnIndexOrThrow("city_id")));
				list.add(county);
			} while (cursor.moveToNext());
		}
		return list;
	}
	
	
}
