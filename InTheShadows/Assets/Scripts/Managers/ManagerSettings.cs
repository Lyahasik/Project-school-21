using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ManagerSettings : MonoBehaviour
{
    public AudioListener CameraAudio;

	private void Start()
	{
		AudioListener.pause = PlayerPrefs.GetInt("AudioPause") == 1 ? true : false;
	}

	public void SwitchPause()
	{
		AudioListener.pause = AudioListener.pause ? false : true;
		PlayerPrefs.SetInt("AudioPause", AudioListener.pause ? 1 : 0);
	}

	public void SetPause(bool value)
	{
		AudioListener.pause = value;
		PlayerPrefs.SetInt("AudioPause", value ? 1 : 0);
	}
}
