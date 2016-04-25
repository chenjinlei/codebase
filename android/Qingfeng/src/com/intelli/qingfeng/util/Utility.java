package com.intelli.qingfeng.util;

import com.intelli.qingfeng.dao.QingfengDB;
import com.intelli.qingfeng.model.City;
import com.intelli.qingfeng.model.County;
import com.intelli.qingfeng.model.Province;

import android.text.TextUtils;

public class Utility {

	/**
	 * 解析和处理服务器返回的省级数据
	 */
	public synchronized static boolean handleProvincesResponse(QingfengDB qingfengDB, String response) {

		if (!TextUtils.isEmpty(response)) {
			String[] allProvinces = response.split(",");
			if (allProvinces != null && allProvinces.length > 0) {
				for (String p : allProvinces) {
					String[] array = p.split("\\|");
					Province province = new Province();
					province.setProvinceCode(array[0]);
					province.setProvinceName(array[1]);
					qingfengDB.saveProvince(province);

				}
			}
			return true;
		}
		return false;

	}

	/**
	 * 解析和处理服务器返回的市级数据
	 */
	public synchronized static boolean handleCitiesResponse(QingfengDB qingfengDB, String response, int provinceId) {

		if (!TextUtils.isEmpty(response)) {
			String[] allCities = response.split(",");
			for (String c : allCities) {
				String[] array = c.split("\\|");
				City city = new City();
				city.setCityCode(array[0]);
				city.setCityName(array[1]);
				city.setProvinceId(provinceId);
				qingfengDB.saveCity(city);

			}
			return true;
		}
		return false;
	}

	/**
	 * 解析和处理服务器返回的县级数据
	 */
	public synchronized static boolean handleCountiesResponse(QingfengDB qingfengDB, String response, int cityId) {
		
		if (!TextUtils.isEmpty(response)) {
			
			String[] allCounties = response.split(",");
			for (String c : allCounties) {
				String[] array = c.split("\\|");
				County county = new County();
				county.setCountyCode(array[0]);
				county.setCountyName(array[1]);
				county.setCityId(cityId);
				qingfengDB.saveCounty(county);
			}
			return true;
		}
		return false;
	}

}
