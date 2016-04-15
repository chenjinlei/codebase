package com.example.choosepictest;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;

import android.app.Activity;
import android.content.Intent;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.net.Uri;
import android.os.Bundle;
import android.os.Environment;
import android.provider.MediaStore;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.ImageView;

public class MainActivity extends Activity implements OnClickListener {

	private static final int TAKE_PHOTO = 1;
	private static final int CROP_PHOTO = 2;

	private Button takePhoto;
	private ImageView picture;
	private Uri imageUri;
	
	private Button chooseFromAlbum;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		takePhoto = (Button) this.findViewById(R.id.take_photo);
		picture = (ImageView) this.findViewById(R.id.picture);
		takePhoto.setOnClickListener(this);
		
		chooseFromAlbum = (Button) this.findViewById(R.id.choose_from_album);
		chooseFromAlbum.setOnClickListener(this);

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
	public void onClick(View v) {

		switch (v.getId()) {
		case R.id.take_photo:
			File outputImage = new File(Environment.getExternalStorageDirectory(), "tempImage.jpg");
			try {
				if (outputImage.exists()) {
					outputImage.delete();
				}
				outputImage.createNewFile();
			} catch (Exception e) {
				e.printStackTrace();
			}

			imageUri = Uri.fromFile(outputImage);
			Intent intent = new Intent("android.media.action.IMAGE_CAPTURE");
			intent.putExtra(MediaStore.EXTRA_OUTPUT, imageUri);
			startActivityForResult(intent, TAKE_PHOTO);
			break;
		case R.id.choose_from_album:
			File outputImage1 = new File(Environment.getExternalStorageDirectory(), "output_image.jpg");
			try {
				if (outputImage1.exists()) {
					outputImage1.delete();
				}
				outputImage1.createNewFile();
			} catch (IOException e) {
				e.printStackTrace();
			}
			imageUri = Uri.fromFile(outputImage1);
			Intent intent1 = new Intent("android.intent.action.GET_CONTENT");
			intent1.setType("image/*");
			intent1.putExtra("crop", true);
			intent1.putExtra("scale", true);
			intent1.putExtra(MediaStore.EXTRA_OUTPUT, imageUri);
			startActivityForResult(intent1, CROP_PHOTO);
			break;
		}

	}

	@Override
	protected void onActivityResult(int requestCode, int resultCode, Intent data) {
		super.onActivityResult(requestCode, resultCode, data);
		switch (requestCode) {
		case TAKE_PHOTO:
			if (resultCode == RESULT_OK) {
				Intent intent = new Intent("com.android.camera.action.CROP");
				intent.setDataAndType(imageUri, "image/*");
				intent.putExtra("scale", true);
				intent.putExtra(MediaStore.EXTRA_OUTPUT, imageUri);
				startActivityForResult(intent, CROP_PHOTO);
			}
			break;
		case CROP_PHOTO:
			if (resultCode == RESULT_OK) {
				try {
					Bitmap bitmap = BitmapFactory.decodeStream(this.getContentResolver().openInputStream(imageUri));
					picture.setImageBitmap(bitmap);
				} catch (FileNotFoundException e) {
					e.printStackTrace();
				}
			}
			break;
		default:
			break;
		}

	}

}
