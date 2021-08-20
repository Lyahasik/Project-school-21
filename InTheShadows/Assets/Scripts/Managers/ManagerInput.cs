using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class ManagerInput : MonoBehaviour, IUpdate
{
	private bool _leftControl { get; set; }

    public void ObjectUpdate()
    {
		CheckKeyboardDown();
		CheckKeyboardUp();
    }

	public bool IsLeftControl()
	{
		return _leftControl;
	}

    void CheckKeyboardDown()
	{
		if (Input.GetKeyDown(KeyCode.LeftControl))
		{
			_leftControl = true;
		}

		if (Input.GetKeyDown(KeyCode.Escape))
		{
			Application.Quit();
		}
	}

    void CheckKeyboardUp()
	{
		if (Input.GetKeyUp(KeyCode.LeftControl))
		{
			_leftControl = false;
		}
	}
}
