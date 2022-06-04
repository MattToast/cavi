import pytest
import cavi

@pytest.fixture(autouse=True)
def set_mock_status():
    """Rest the mock status used to abstract hardware for testing"""
    yield
    cavi._cavi._testing.reset_mock_status()
