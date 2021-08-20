using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ButtonTest : MonoBehaviour
{
	public ManagerLevels ManagerLevels;
	public ManagerInput ManagerInput;

	private void OnMouseDown()
	{
		if (ManagerInput.IsLeftControl() == true)
		{
			ManagerLevels.ResetGame();
		}
		else
		{
			ManagerLevels.SwitchTestMode();	
		}
	}
}
