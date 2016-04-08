package com.example.listviewtest;

import java.util.ArrayList;

import com.example.listview.adapter.FruitAdapter;
import com.example.listview.model.Fruit;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemClickListener;
import android.widget.ListView;
import android.widget.Toast;

public class MainActivity extends Activity implements OnItemClickListener {

//	private String[] data = { "Apple", "Banana", "Orange", "Watermelon", "Pear", "Grape", "Pineapple", "Strawberry",
//			"Cherry", "Mango" };
	private ArrayList<Fruit> fruitList = new ArrayList<Fruit>();

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		initFruits();
//		ArrayAdapter<String> adapter = new ArrayAdapter<String>(MainActivity.this,
//				android.R.layout.simple_list_item_1, data);
		FruitAdapter adapter = new FruitAdapter(MainActivity.this, R.layout.fruit_item, fruitList);//TODO
		ListView listView = (ListView) findViewById(R.id.list_view);
		listView.setAdapter(adapter);
		listView.setOnItemClickListener(this);
	}
	
	private void initFruits() {
		Fruit apple = new Fruit("Apple", R.drawable.apple_pic);
		fruitList.add(apple);
		Fruit banana = new Fruit("Banana", R.drawable.banana_pic);
		fruitList.add(banana);
		Fruit cherry = new Fruit("Cherry", R.drawable.cherry_pic);
		fruitList.add(cherry);
		Fruit grape = new Fruit("Grape", R.drawable.grape_pic);
		fruitList.add(grape);
		Fruit mango = new Fruit("Mango", R.drawable.mango_pic);
		fruitList.add(mango);
		Fruit orange = new Fruit("Orange", R.drawable.orange_pic);
		fruitList.add(orange);
		Fruit pear = new Fruit("Pear", R.drawable.pear_pic);
		fruitList.add(pear);
		Fruit pineapple = new Fruit("Pineapple", R.drawable.pineapple_pic);
		fruitList.add(pineapple);
		Fruit strawberry = new Fruit("Strawberry", R.drawable.strawberry_pic);
		fruitList.add(strawberry);
		Fruit watermelon = new Fruit("Watermelon", R.drawable.watermelon_pic);
		fruitList.add(watermelon);
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}

	@Override
	public boolean onOptionsItemSelected(MenuItem item) {
		// Handle action bar item clicks here. The action bar will
		// automatically handle clicks on the Home/Up button, so long
		// as you specify a parent activity in AndroidManifest.xml.
		int id = item.getItemId();
		if (id == R.id.action_settings) {
			return true;
		}
		return super.onOptionsItemSelected(item);
	}

	@Override
	public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
		Fruit fruit = fruitList.get(position);
		Toast.makeText(MainActivity.this, fruit.getName(), Toast.LENGTH_SHORT).show();
	}
}
