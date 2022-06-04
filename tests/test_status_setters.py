from cavi import status


def test_set_abort():
    assert status.get_abort() == 0
    assert status.set_abort(1)
    assert status.get_abort() == 1
    assert status.set_abort(0)
    assert status.get_abort() == 0


def test_set_launch():
    assert status.get_launch() == 0
    assert status.set_launch(1)
    assert status.get_launch() == 1
    assert status.set_launch(0)
    assert status.get_launch() == 0


def test_set_qdm():
    assert status.get_qdm() == 0
    assert status.set_qdm(1)
    assert status.get_qdm() == 1
    assert status.set_qdm(0)
    assert status.get_qdm() == 0


def test_set_arm():
    assert status.get_arm() == 0
    assert status.set_arm(1)
    assert status.get_arm() == 1
    assert status.set_arm(0)
    assert status.get_arm() == 0


def test_get_stabilize():
    assert status.get_stabilize() == 0
    assert status.set_stabilize(1)
    assert status.get_stabilize() == 1
    assert status.set_stabilize(0)
    assert status.get_stabilize() == 0
