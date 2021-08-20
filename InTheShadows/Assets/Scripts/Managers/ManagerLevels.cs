using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class ManagerLevels : MonoBehaviour, IUpdate
{
	public ManagerSettings ManagerSettings;
	[Space]

	public GameObject Levels;
    public GameObject[] ListLevels;
	[Space]

	public GameObject Camera;
	public Image CameraVeil;
	[Space]

	public Light DirectionLight;
	public Light LampLight;

	private int _currentLevel;
	private int _numberLevels;
	private int _lastOpenLevel;

	private bool _startScene;

	private bool _froze;
	private bool _startLevel;

	private bool _testMode;

	private void Start()
	{
		StartScene();
		_currentLevel = PlayerPrefs.GetInt("CurrentLevel");
		_lastOpenLevel = PlayerPrefs.GetInt("LastOpenLevel");
		_testMode = PlayerPrefs.GetInt("TestMode") == 1 ? true : false;
		ChangeTestSetting();

		StartPosition();

		_numberLevels = ListLevels.Length;

		ListLevels[0].GetComponent<Level>().SwitchOpen();
	}

	public void ResetGame()
	{
		PlayerPrefs.SetInt("CurrentLevel", 0);
		_currentLevel = PlayerPrefs.GetInt("CurrentLevel");

		PlayerPrefs.SetInt("LastOpenLevel", 0);
		_lastOpenLevel = PlayerPrefs.GetInt("LastOpenLevel");

		ManagerSettings.SetPause(false);
		
		_testMode = false;
		PlayerPrefs.SetInt("TestMode", 0);
		ChangeTestSetting();

		foreach (GameObject level in ListLevels)
		{
			level.GetComponent<Level>().ResetLevel();
			level.GetComponent<Level>().SetTestMode(false);
		}
	}

	private void StartPosition()
	{
		Vector3 _levelsPosition = Levels.transform.position;
		Vector3 _levelPosition = ListLevels[_currentLevel].transform.position;
		Vector3 _cameraPosition = Camera.transform.position;

		Levels.transform.position = new Vector3(_levelsPosition.x - (_levelPosition.x - _cameraPosition.x),
												_levelsPosition.y,
												_levelsPosition.z);
	}

	public void ObjectUpdate()
	{
		ProcessStartScene();
		MoveLevels();
		ProcessStart();
	}

	#region ProcessScenes

	private void StartScene()
	{
		_startScene = PlayerPrefs.GetInt("StartScene") == 1 ? true : false;

		if (_startScene == true)
		{
			CameraVeil.color = new Color(CameraVeil.color.r,
												CameraVeil.color.g,
												CameraVeil.color.b,
												1.0f);
			Camera.transform.position = new Vector3(Camera.transform.position.x,
													Camera.transform.position.y,
													-3.0f);
		}
	}

	private void ProcessStartScene()
	{
		if (_startScene == true)
		{
			if (CameraVeil.color.a > 0.0f)
			{
				CameraVeil.color = new Color(CameraVeil.color.r,
												CameraVeil.color.g,
												CameraVeil.color.b,
												CameraVeil.color.a - 2.0f * Time.deltaTime);
			}
			else if (Camera.transform.position.z > -30.0f)
			{
				Camera.transform.position -= Vector3.forward * 20.0f * Time.deltaTime;
			}
			else
			{
				_startScene = false;
				PlayerPrefs.SetInt("StartScene", 0);
				OpenLevel();
			}
		}
	}

	public void StartLevel(int numberLevel)
	{
		if (_startScene == false && _froze == true && numberLevel == _currentLevel)
		{
			_startLevel = true;
		}
	}

	private void ProcessStart()
	{
		if (_startLevel == true)
		{
			if (Camera.transform.position.z < ListLevels[_currentLevel].transform.position.z)
			{
				Camera.transform.position += Vector3.forward * 20.0f * Time.deltaTime;
			}
			else if (CameraVeil.color.a < 1.0f)
			{
				CameraVeil.color = new Color(CameraVeil.color.r,
												CameraVeil.color.g,
												CameraVeil.color.b,
												CameraVeil.color.a + 2.0f * Time.deltaTime);
			}
			else
			{
				SceneManager.LoadScene(ListLevels[_currentLevel].name);
			}
		}
	}

	#endregion ProcessScenes

	public void ChangeLevel(int numberLevel)
	{
		if (_testMode == true)
		{
			if (numberLevel < _numberLevels)
			{
				_currentLevel = numberLevel;
				PlayerPrefs.SetInt("CurrentLevel", _currentLevel);
			}
		}
		else
		{
			if (numberLevel <= _lastOpenLevel && numberLevel < _numberLevels)
			{
				_currentLevel = numberLevel;
				PlayerPrefs.SetInt("CurrentLevel", _currentLevel);
			}
		}
	}

	#region Moving

	private void MoveLevels()
	{
		if (_startLevel == false)
		{
			if (Mathf.Abs(ListLevels[_currentLevel].transform.position.x - Camera.transform.position.x) > 0.1f)
			{
				_froze = false;
				Vector3 level = new Vector3(ListLevels[_currentLevel].transform.position.x, 0, 0);
				Vector3 camera = new Vector3(Camera.transform.position.x, 0, 0);

				Vector3 shift = Vector3.Lerp(level, camera, 0.03f);
				shift = Vector3.Lerp(Vector3.zero, shift, 0.03f);

				Levels.transform.position -= shift;
			}
			else
			{
				_froze = true;
			}
		}
	}

	#endregion Moving

	#region Openness

	public void OpenLevel()
	{
		if (PlayerPrefs.GetInt("LastOpenLevel") == PlayerPrefs.GetInt("CurrentLevel") + 1)
		{
			ListLevels[_currentLevel].GetComponent<Level>().SwitchDecided();
			_lastOpenLevel = PlayerPrefs.GetInt("LastOpenLevel");

			if (_lastOpenLevel < _numberLevels)
			{
				ListLevels[_lastOpenLevel].GetComponent<Level>().SwitchOpen();
			}
		}
	}

	#endregion Openness

	#region Testing

	public void SwitchTestMode()
	{
		_testMode = _testMode ? false : true;

		ChangeTestSetting();
		UpdateTest();
	}

	private void ChangeTestSetting()
	{
		if (_testMode == true)
		{
			LampLight.enabled = true;
			DirectionLight.intensity = 7.0f;

			PlayerPrefs.SetInt("TestMode", 1);
		}
		else
		{
			if (_currentLevel > _lastOpenLevel)
			{
				_currentLevel = _lastOpenLevel;
				PlayerPrefs.SetInt("CurrentLevel", _currentLevel);
			}

			LampLight.enabled = false;
			DirectionLight.intensity = 0.0f;

			PlayerPrefs.SetInt("TestMode", 0);
		}
	}

	private void UpdateTest()
	{
		foreach (GameObject level in ListLevels)
		{
			level.GetComponent<Level>().SwitchTestMode();
		}
	}

	#endregion Testing
}
