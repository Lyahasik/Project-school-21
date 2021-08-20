using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class ManagerLevel : MonoBehaviour, IUpdate
{

	public Image CameraVeil;

	private bool _loadingScene = true;
	private bool _closingScene;

	private bool _autoTurn;

	public void ObjectUpdate()
	{
		ProcessStartScene();
		ProcessClosedScene();
	}

	public void SetAutoTurn(bool autoTurn)
	{
		_autoTurn = autoTurn;
	}

	private void ProcessStartScene()
	{
		if (_loadingScene == true)
		{
			if (CameraVeil.color.a > 0.0f)
			{
				CameraVeil.color = new Color(CameraVeil.color.r,
												CameraVeil.color.g,
												CameraVeil.color.b,
												CameraVeil.color.a - 2.0f * Time.deltaTime);
			}
			else
			{
				_loadingScene = false;
			}
		}
	}

	public void LevelSuccess()
	{
		if (PlayerPrefs.GetInt("TestMode") == 0)
		{
			if (PlayerPrefs.GetInt("CurrentLevel") == PlayerPrefs.GetInt("LastOpenLevel"))
			{
				PlayerPrefs.SetInt("LastOpenLevel", PlayerPrefs.GetInt("CurrentLevel") + 1);
			}
		}

		ClosingScene();
	}

	public void ClosingScene()
	{
		if (_autoTurn == false)
		{
			_closingScene = true;
		}
	}

	private void ProcessClosedScene()
	{
		if (_closingScene == true)
		{
			if (CameraVeil.color.a < 1.0f)
			{
				CameraVeil.color = new Color(CameraVeil.color.r,
												CameraVeil.color.g,
												CameraVeil.color.b,
												CameraVeil.color.a + 2.0f * Time.deltaTime);
			}
			else
			{
				LevelExit();
			}
		}
	}

	private void LevelExit()
	{
		PlayerPrefs.SetInt("StartScene", 1);
		SceneManager.LoadScene("Main");
	}
}
