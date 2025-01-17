﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.XR.MagicLeap;

public class ControlScript6DOFNoProjectile : MonoBehaviour
{

    #region Private Variables
    private MLInputController _controller;
    #endregion

    #region Unity Methods

    // Use this for initialization
    void Start()
    {
        MLInput.Start();
        _controller = MLInput.GetController(MLInput.Hand.Left);
    }

    private void OnDestroy()
    {
        MLInput.Stop();
    }

    // Update is called once per frame
    void Update()
    {
        transform.position = _controller.Position;
        transform.rotation = _controller.Orientation;
    }
    #endregion
}