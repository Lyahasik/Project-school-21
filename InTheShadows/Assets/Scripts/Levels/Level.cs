using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Level : MonoBehaviour, IUpdate
{
	public ManagerLevels ManagerLevels;
	public int NumberLevel = 0;
	[Space]

	public GameObject PointLight;
	public float MaxIntensityLight = 13.0f;
	[Space]

	public Image Image;
	public float SpeedTransitionImage = 10.0f;
	[Space]

	public Text Text;
	public float SpeedTransitionText = 10.0f;
	[Space]

	public float SpeedTransitionLight = 13.0f;

	private float _frameTimeImage;
	private float _frameTimeText;
	private float _frameTimeLight;

	private bool _testMode;

	private Light _componentLight;

	private bool _open;
	private bool _decided;

	private void Start()
	{
		_testMode = PlayerPrefs.GetInt("TestMode") == 1 ? true : false;
		_open = PlayerPrefs.GetInt(gameObject.name + "Open") == 1 ? true : false;
		_decided = PlayerPrefs.GetInt(gameObject.name + "Decided") == 1 ? true : false;

		_componentLight = PointLight.GetComponent<Light>();

		_frameTimeImage = 1.0f / SpeedTransitionImage;
		_frameTimeText = 1.0f / SpeedTransitionText;
		_frameTimeLight = MaxIntensityLight / SpeedTransitionLight;
	}

	public void ResetLevel()
	{
		PlayerPrefs.SetInt(gameObject.name + "Open", NumberLevel == 0 ? 1 : 0);
		_open = NumberLevel == 0 ? true : false;

		PlayerPrefs.SetInt(gameObject.name + "Decided", 0);
		_decided = false;

		_componentLight.intensity = 1.23f;
		Text.color = new Color(Text.color.r, Text.color.g, Text.color.b, 0.0f);
	}

	public void ObjectUpdate()
	{
		Testing();
		Opening();
		Solution();
	}

	#region Testing

	public void SwitchTestMode()
	{
		_testMode = _testMode ? false : true;
	}

	public void SetTestMode(bool value)
	{
		_testMode = value;
	}

	private void Testing()
	{
		if (_testMode == true)
		{
			Text.color = new Color(Text.color.r, Text.color.g, Text.color.b, 0.0f);
			Image.color = new Color(Image.color.r, Image.color.g, Image.color.b, 1.0f);
			_componentLight.intensity = 1.23f;
		}
		else
		{
			Opening();
			Solution();
		}
	}

	#endregion Testing

	#region Opening

	public void SwitchOpen()
	{
		if (_decided == true)
		{
			_open = false;
			PlayerPrefs.SetInt(gameObject.name + "Open", 0);
		}
		else
		{
			_open = true;
			PlayerPrefs.SetInt(gameObject.name + "Open", 1);
		}
	}

	private void Opening()
	{
		if (_testMode == false && _open == true)
		{
			if (Text.color.a < 1.0f)
			{
				Text.color = new Color(Text.color.r,
										Text.color.g,
										Text.color.b,
										Text.color.a + _frameTimeText * Time.deltaTime);
			}
		}
	}

	#endregion Opening

	#region Solution

	public void SwitchDecided()
	{
		_decided = true;
		SwitchOpen();
		PlayerPrefs.SetInt(gameObject.name + "Decided", 1);
	}

	private void Solution()
	{
		if (_testMode == false)
		{
			if (_decided == true)
			{
				if (Text.color.a > 0.0f)
				{
					Text.color = new Color(Text.color.r,
											Text.color.g,
											Text.color.b,
											Text.color.a - _frameTimeText * Time.deltaTime);
				}
				if (Image.color.a < 1.0f)
				{
					Image.color = new Color(Image.color.r,
											Image.color.g,
											Image.color.b,
											Image.color.a + _frameTimeImage * Time.deltaTime);
				}
				if (_componentLight.intensity < MaxIntensityLight)
				{
					_componentLight.intensity += _frameTimeLight * Time.deltaTime;
				}
			}
			else
			{
				if (Image.color.a > 0.0f)
				{
					Image.color = new Color(Image.color.r, Image.color.g, Image.color.b, 0.0f);
				}
			}
		}
	}

	#endregion Solution

	private void OnMouseDown()
	{
		ManagerLevels.StartLevel(NumberLevel);
		ManagerLevels.ChangeLevel(NumberLevel);
	}
}
